#include "cub3d.h"

extern int world_map[MAP_WIDTH][MAP_HEIGHT];

void	set_draw_textured_wall(t_draw *draw, const t_hit hit_point)
{
	draw->line_height = (int)(SCREEN_HEIGHT / hit_point.perp_wall_dist);
	draw->beg = calc_max((SCREEN_HEIGHT / 2) - (draw->line_height / 2), 0);
	draw->end = calc_min((SCREEN_HEIGHT / 2) + (draw->line_height / 2), SCREEN_HEIGHT - 1);
	draw->y = 0;
	draw->ty = 0;
}

void	draw_textured_wall(
		int *data,
		t_texture texture,
		t_draw draw,
		t_hit hit_point)
{
	double tpos;
	double step_ty;

	set_draw_textured_wall(&draw, hit_point);
    step_ty = 1.0 * texture.height / draw.line_height;
	tpos = ((double)draw.beg - (double)SCREEN_HEIGHT / 2 + (double)draw.line_height / 2) * step_ty;
	while (draw.y < draw.beg) data[(draw.y++) * SCREEN_WIDTH + draw.x] = COLOR_CEIL;
	while (draw.y < draw.beg + draw.line_height)
	{
	    draw.ty = (int)tpos & (texture.height - 1);
	    tpos += step_ty;
	    hit_point.color = texture.data[draw.ty * texture.width + draw.tx];
	    if (hit_point.side == 1)
	        hit_point.color = (hit_point.color >> 1) & 8355711;
	    data[(draw.y++) * SCREEN_WIDTH + draw.x] = hit_point.color;
	}
	while (draw.y < SCREEN_HEIGHT)
		data[(draw.y++) * SCREEN_WIDTH + draw.x] = COLOR_FLOOR;
}

int		get_textured_tx(
		const t_texture texture,
		const t_player player,
		const t_hit hit_point,
		const t_vecd ray_dir)
{
	double	wall_t;
	int		ret;

	if (hit_point.side == 0)
		wall_t = player.pos.y + hit_point.perp_wall_dist * ray_dir.y;
	else
		wall_t = player.pos.x + hit_point.perp_wall_dist * ray_dir.x;
	wall_t -= floor(wall_t);
	ret = (int)(wall_t * (double)(texture.width));
	if(hit_point.side == 0 && ray_dir.x > 0)
		ret = texture.width - ret - 1;
	if(hit_point.side == 1 && ray_dir.y < 0)
		ret	 = texture.width - ret - 1;
	return (ret);
}

int		draw_textured_line(
		t_disp disp,
		const t_player player,
		const int x,
		const t_hit hit_point)
{
	double		wall_t;
	int			tnum;
	t_draw		draw;

	tnum = world_map[hit_point.x][hit_point.y] - 1;

	draw.x = x;
	draw.tx = get_textured_tx(disp.texture[tnum], player, hit_point, player.ray_dir);	
	draw_textured_wall(disp.img.data, disp.texture[tnum], draw, hit_point);
	return (1);	
}
