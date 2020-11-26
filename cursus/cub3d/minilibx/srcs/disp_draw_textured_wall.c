#include "cub3d.h"

extern int world_map[MAP_WIDTH][MAP_HEIGHT];

t_tex	get_wall_type(t_disp disp, t_player player, t_hit hit_point)
{
	t_tex	ret;

	// dir 0일 때 신경쓰기
	// N:0, E:1, W:2, S:3
	if (hit_point.side == 1)
	{
		if (player.ray_dir.y > 0)
			ret = disp.tex[TEXTURE_N];
		else
			ret = disp.tex[TEXTURE_S];
	}
	else
	{
		if (player.ray_dir.x > 0)
			ret = disp.tex[TEXTURE_E];
		else
			ret = disp.tex[TEXTURE_W];
	}
	return (ret);
}

int		get_tex_tx(t_tex tex, t_player player, t_hit hit_point,	t_vecd ray_dir)
{
	double	wall_t;
	int		ret;

	if (hit_point.side == 0)
		wall_t = player.pos.y + hit_point.perp_wall_dist * ray_dir.y;
	else
		wall_t = player.pos.x + hit_point.perp_wall_dist * ray_dir.x;
	wall_t -= floor(wall_t);
	ret = (int)(wall_t * (double)(tex.width));
	#if 1
	if(hit_point.side == 0 && ray_dir.x > 0)
		ret = tex.width - ret - 1;
	if(hit_point.side == 1 && ray_dir.y < 0)
		ret	 = tex.width - ret - 1;
	#endif
	return (ret);
}

void	set_draw_tex_wall(t_draw *draw, t_hit hit_point)
{
	if (fabs(hit_point.perp_wall_dist - 0.0) < EPSILON)
		draw->line_height = (int)(SCREEN_HEIGHT * 2);
	else
		draw->line_height = (int)(SCREEN_HEIGHT / hit_point.perp_wall_dist);
	draw->beg = (int)fmax(((double)SCREEN_HEIGHT - draw->line_height) / 2, 0);
	draw->end = (int)fmin(((double)SCREEN_HEIGHT + draw->line_height) / 2, SCREEN_HEIGHT - 1);
	draw->y = 0;
	draw->ty = 0;
}

void	draw_tex_wall_part(int *data, t_tex tex, t_draw draw, t_hit hit_point)
{
	double tpos;
	double step_ty;

	set_draw_tex_wall(&draw, hit_point);
    step_ty = 1.0 * tex.height / draw.line_height;
	tpos = ((double)draw.beg - (double)SCREEN_HEIGHT / 2 + (double)draw.line_height / 2) * step_ty;
	while (draw.y < draw.beg)
		data[(draw.y++) * SCREEN_WIDTH + draw.x] = COLOR_CEIL;
	while (draw.y < draw.end)
	{
	    //draw.ty = (int)tpos & (tex.height - 1);
		draw.ty = (int)fmin(tpos, (double)tex.height - 1); 
	    hit_point.color = tex.data[draw.ty * tex.width + draw.tx];
	    if (hit_point.side == 1)
	        hit_point.color = (hit_point.color >> 1) & 8355711;
	    data[(draw.y++) * SCREEN_WIDTH + draw.x] = hit_point.color;
	    tpos += step_ty;
	}
	while (draw.y < SCREEN_HEIGHT)
		data[(draw.y++) * SCREEN_WIDTH + draw.x] = COLOR_FLOOR;
}


int		draw_tex_wall(t_disp disp, t_player player, int x, t_hit hit_point)
{
	double		wall_t;
	int			tnum;
	t_draw		draw;
	t_tex		wall_type;

	draw.x = x;
#if 0
	tnum = world_map[hit_point.pos.x][hit_point.pos.y] - 1;
	draw.tx = get_tex_tx(disp.tex[tnum], player, hit_point, player.ray_dir);	
	draw_tex_wall_part(disp.img.data, disp.tex[tnum], draw, hit_point);
#endif
#if 1
	wall_type = get_wall_type(disp, player, hit_point);	
	draw.tx = get_tex_tx(wall_type, player, hit_point, player.ray_dir);	
	draw_tex_wall_part(disp.img.data, wall_type, draw, hit_point);
#endif
	return (1);	
}
