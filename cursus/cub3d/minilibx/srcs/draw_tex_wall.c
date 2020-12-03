#include "cub3d.h"

t_tex	get_wall_type(t_disp disp, t_player player, t_hit hit_point)
{
	if (hit_point.door_type == MAP_SECRET_VAL)
		return (disp.tex[CONFIG_SECRET]);
	if (hit_point.door_type == MAP_OPDOOR_VAL)
		return (disp.tex[CONFIG_OPDOOR]);
	if (hit_point.side == HIT_SIDE_Y)
	{
		if (player.ray_dir.y > 0)
			return (disp.tex[CONFIG_NO]);
		else
			return (disp.tex[CONFIG_SO]);
	}
	else
	{
		if (player.ray_dir.x > 0)
			return (disp.tex[CONFIG_EA]);
		else
			return (disp.tex[CONFIG_WE]);
	}
	return (disp.tex[CONFIG_NO]);
}

int		get_tex_tx(t_tex tex, t_player player, t_hit hit_point,	t_vecd ray_dir)
{
	int		ret;
	double	wall_t;

	if (hit_point.side == HIT_SIDE_X)
		wall_t = player.pos.y + hit_point.perp_wall_dist * ray_dir.y;
	else
		wall_t = player.pos.x + hit_point.perp_wall_dist * ray_dir.x;
	wall_t -= floor(wall_t);
	ret = (int)(wall_t * (double)(tex.w));
	if(hit_point.side == HIT_SIDE_X && ray_dir.x > 0)
		ret = tex.w - ret - 1;
	if(hit_point.side == HIT_SIDE_Y && ray_dir.y < 0)
		ret	 = tex.w - ret - 1;
	return (ret);
}

void	set_draw_tex_wall(t_disp disp, t_draw *draw, t_hit hit_point)
{
	if (fabs(hit_point.perp_wall_dist - 0.0) < EPSILON)
		draw->lh = (int)(disp.h * 2);
	else
		draw->lh = (int)(disp.h / hit_point.perp_wall_dist);
	draw->beg = (int)fmax(((double)disp.h - draw->lh) / 2, 0);
	draw->end = (int)fmin(((double)disp.h + draw->lh) / 2, disp.h - 1);
	draw->y = 0;
	draw->ty = 0;
}

void	draw_tex_wall_part(t_disp disp, t_tex tex, t_draw draw, t_hit hit_point)
{
	double tpos;
	double step_ty;

	set_draw_tex_wall(disp, &draw, hit_point);
    step_ty = 1.0 * tex.h / draw.lh;
	tpos = (double)draw.beg - (double)(disp.h - draw.lh) / 2;
	tpos *= step_ty;
	draw.y = draw.beg;
	while (draw.y < draw.end)
	{
		draw.ty = (int)fmin(tpos, (double)tex.h - 1); 
	    hit_point.color = tex.data[draw.ty * tex.w + draw.tx];
	    if (hit_point.side == HIT_SIDE_Y)
	        hit_point.color = (hit_point.color >> 1) & 8355711;
	    disp.img.data[(draw.y++) * disp.w + draw.x] = hit_point.color;
	    tpos += step_ty;
	}
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
