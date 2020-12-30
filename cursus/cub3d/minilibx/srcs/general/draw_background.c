/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:22:40 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 13:40:35 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_draw	set_background_draw(t_disp *disp, int flag)
{
	t_draw	ret;

	ret.yctr = (int)(0.5 * disp->h) + disp->hctr_bias;
	if (flag)
	{
		ret.y = ret.yctr + 1 - 1;
		ret.yend = disp->h - 1;
	}
	else
	{
		ret.y = 0 - 1;
		ret.yend = ret.yctr - 1;
	}
	ret.xend = disp->w - 1;
	return (ret);
}

static void		draw_ceil(t_disp *disp, t_player *player, t_bg *bg, t_tex *tex)
{
	t_vecd	ceil;

	bg->draw = set_background_draw(disp, 0);
	while (++bg->draw.y <= bg->draw.yend)
	{
		bg->row_dist = (double)bg->draw.yctr / (bg->draw.yctr - bg->draw.y);
		bg->step.x = bg->row_dist * (bg->ray_dir1.x - bg->ray_dir0.x) / disp->w;
		bg->step.y = bg->row_dist * (bg->ray_dir1.y - bg->ray_dir0.y) / disp->w;
		ceil.x = player->pos.x + bg->row_dist * bg->ray_dir0.x;
		ceil.y = player->pos.y + bg->row_dist * bg->ray_dir0.y;
		bg->draw.x = -1;
		while (++bg->draw.x <= bg->draw.xend)
		{
			bg->draw.tx = (int)fmin(tex->w\
							* (ceil.x - (int)ceil.x), tex->w - 1);
			bg->draw.ty = (int)fmin(tex->h\
							* (ceil.y - (int)ceil.y), tex->h - 1);
			bg->draw.color = tex->data[bg->draw.ty * tex->w + bg->draw.tx];
			bg->draw.color = (bg->draw.color >> 1) & 8355711;
			disp->img.data[bg->draw.y * disp->w + bg->draw.x] = bg->draw.color;
			ceil.x += bg->step.x;
			ceil.y += bg->step.y;
		}
	}
}

static void		draw_floor(t_disp *disp, t_player *player, t_bg *bg, t_tex *tex)
{
	t_vecd	floor;

	bg->draw = set_background_draw(disp, 1);
	while (++bg->draw.y <= bg->draw.yend)
	{
		bg->row_dist = (double)bg->draw.yctr / (bg->draw.y - bg->draw.yctr);
		bg->step.x = bg->row_dist * (bg->ray_dir1.x - bg->ray_dir0.x) / disp->w;
		bg->step.y = bg->row_dist * (bg->ray_dir1.y - bg->ray_dir0.y) / disp->w;
		floor.x = player->pos.x + bg->row_dist * bg->ray_dir0.x;
		floor.y = player->pos.y + bg->row_dist * bg->ray_dir0.y;
		bg->draw.x = -1;
		while (++bg->draw.x <= bg->draw.xend)
		{
			bg->draw.tx = (int)fmin(tex->w\
							* (floor.x - (int)floor.x), tex->w - 1);
			bg->draw.ty = (int)fmin(tex->h\
							* (floor.y - (int)floor.y), tex->h - 1);
			bg->draw.color = tex->data[bg->draw.ty * tex->w + bg->draw.tx];
			bg->draw.color = (bg->draw.color >> 1) & 8355711;
			disp->img.data[bg->draw.y * disp->w + bg->draw.x] = bg->draw.color;
			floor.x += bg->step.x;
			floor.y += bg->step.y;
		}
	}
}

int				draw_background(t_disp *disp, t_player *player)
{
	t_bg	bg;

	bg.ray_dir0.x = player->dir.x - player->plane.x;
	bg.ray_dir0.y = player->dir.y - player->plane.y;
	bg.ray_dir1.x = player->dir.x + player->plane.x;
	bg.ray_dir1.y = player->dir.y + player->plane.y;
	draw_floor(disp, player, &bg, &disp->tex[TEXTURE_FLOOR]);
	draw_ceil(disp, player, &bg, &disp->tex[CONFIG_SO]);
	return (0);
}
