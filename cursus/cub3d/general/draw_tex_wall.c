/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:32:34 by yekim             #+#    #+#             */
/*   Updated: 2020/12/31 18:07:03 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_tex	get_wall_type(
				t_disp *disp,
				t_player *player,
				t_hit *hp)
{
	if (hp->side == HIT_SIDE_Y)
	{
		if (player->ray_dir.y > 0)
			return (disp->tex[CONFIG_NO]);
		else
			return (disp->tex[CONFIG_SO]);
	}
	else
	{
		if (player->ray_dir.x > 0)
			return (disp->tex[CONFIG_EA]);
		else
			return (disp->tex[CONFIG_WE]);
	}
	return (disp->tex[CONFIG_NO]);
}

static int		get_tex_tx(
				t_tex tex,
				t_player *player,
				t_hit *hit_point,
				t_vecd ray_dir)
{
	int		ret;
	double	wall_t;

	if (hit_point->side == HIT_SIDE_X)
		wall_t = player->pos.y + hit_point->perp_wall_dist * ray_dir.y;
	else
		wall_t = player->pos.x + hit_point->perp_wall_dist * ray_dir.x;
	wall_t -= floor(wall_t);
	ret = (int)(wall_t * (double)(tex.w));
	if (hit_point->side == HIT_SIDE_X && ray_dir.x > 0)
		ret = tex.w - ret - 1;
	if (hit_point->side == HIT_SIDE_Y && ray_dir.y < 0)
		ret = tex.w - ret - 1;
	return (ret);
}

static t_draw	set_tex_wall_draw(
				t_disp *disp,
				t_hit hit_point)
{
	t_draw	ret;

	ret.yctr = (double)disp->h / 2 + disp->hctr_bias;
	if (fabs(hit_point.perp_wall_dist - 0.0) < EPSILON)
		ret.lh = (int)(disp->h * 2);
	else
		ret.lh = (int)(disp->h / hit_point.perp_wall_dist);
	ret.ybeg = (int)fmax(ret.yctr - ((double)ret.lh) / 2, 0);
	ret.yend = (int)fmin(ret.yctr + ((double)ret.lh) / 2, disp->h - 1);
	ret.y = ret.ybeg - 1;
	ret.ty = 0;
	return (ret);
}

static void		draw_tex_wall_part(
				t_disp *disp,
				t_draw *draw,
				t_tex tex,
				t_hit *hit_point)
{
	double	tpos;
	double	step_ty;

	(void)hit_point;
	step_ty = (double)tex.h / draw->lh;
	tpos = draw->ybeg - draw->yctr + (double)draw->lh / 2;
	tpos *= step_ty;
	while (++(draw->y) < draw->yend)
	{
		draw->ty = (int)fmin(tpos, (double)tex.h - 1);
		draw->color = tex.data[draw->ty * tex.w + draw->tx];
		disp->img.data[draw->y * disp->w + draw->x] = draw->color;
		tpos += step_ty;
	}
}

int				draw_tex_wall(
				t_disp *disp,
				t_player *p,
				int x,
				t_hit *hp)
{
	t_tex	wall_type;
	t_draw	draw;

	draw = set_tex_wall_draw(disp, *hp);
	draw.x = x;
	wall_type = get_wall_type(disp, p, hp);
	draw.tx = get_tex_tx(wall_type, p, hp, p->ray_dir);
	draw_tex_wall_part(disp, &draw, wall_type, hp);
	return (0);
}
