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
			ret = disp.tex[CONFIG_NO];
		else
			ret = disp.tex[CONFIG_SO];
	}
	else
	{
		if (player.ray_dir.x > 0)
			ret = disp.tex[CONFIG_EA];
		else
			ret = disp.tex[CONFIG_WE];
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

void	set_draw_tex_wall(t_disp disp, t_draw *draw, t_hit hit_point)
{
	if (fabs(hit_point.perp_wall_dist - 0.0) < EPSILON)
		draw->line_height = (int)(disp.height * 2);
	else
		draw->line_height = (int)(disp.height / hit_point.perp_wall_dist);
	draw->beg = (int)fmax(((double)disp.height - draw->line_height) / 2, 0);
	draw->end = (int)fmin(((double)disp.height + draw->line_height) / 2, disp.height - 1);
	draw->y = 0;
	draw->ty = 0;
}

void	draw_tex_wall_part(t_disp disp, t_tex tex, t_draw draw, t_hit hit_point)
{
	double tpos;
	double step_ty;

	set_draw_tex_wall(disp, &draw, hit_point);
    step_ty = 1.0 * tex.height / draw.line_height;
	tpos = ((double)draw.beg - (double)disp.height / 2 + (double)draw.line_height / 2) * step_ty;
	while (draw.y < draw.beg)
		disp.img.data[(draw.y++) * disp.width + draw.x] = disp.ceil_color;
	while (draw.y < draw.end)
	{
		draw.ty = (int)fmin(tpos, (double)tex.height - 1); 
	    hit_point.color = tex.data[draw.ty * tex.width + draw.tx];
	    if (hit_point.side == 1)
	        hit_point.color = (hit_point.color >> 1) & 8355711;
	    disp.img.data[(draw.y++) * disp.width + draw.x] = hit_point.color;
	    tpos += step_ty;
	}
	while (draw.y < disp.height)
		disp.img.data[(draw.y++) * disp.width + draw.x] = disp.floor_color;
}


int		draw_tex_wall(t_disp disp, t_player player, int x, t_hit hit_point)
{
	double		wall_t;
	int			tnum;
	t_draw		draw;
	t_tex		wall_type;

	draw.x = x;
	wall_type = get_wall_type(disp, player, hit_point);	
	draw.tx = get_tex_tx(wall_type, player, hit_point, player.ray_dir);	
	draw_tex_wall_part(disp, wall_type, draw, hit_point);
	return (1);	
}
