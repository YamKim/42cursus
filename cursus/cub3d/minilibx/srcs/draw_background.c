/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:22:40 by yekim             #+#    #+#             */
/*   Updated: 2020/12/25 00:17:36 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		draw_ceil(t_disp *disp, t_player *player, t_vecd ray_dir1, t_vecd ray_dir0, t_tex *tex)
{
	t_draw	draw;
	t_vecd	ceil_step;
	t_vecd	ceil;

	draw.yctr = (int)(0.5 * disp->h) + disp->hctr_bias;
	for(int y = 0; y < draw.yctr; ++y)
	{
		double row_dist = (double)draw.yctr / (draw.yctr - y);
		ceil_step.x = row_dist * (ray_dir1.x - ray_dir0.x) / disp->w;
		ceil_step.y = row_dist * (ray_dir1.y - ray_dir0.y) / disp->w;
		ceil.x = player->pos.x + row_dist * ray_dir0.x;
		ceil.y = player->pos.y + row_dist * ray_dir0.y;
		for(int x = 0; x < disp->w; ++x)
		{
			draw.tx = (int)fmin(tex->w * (ceil.x - (int)ceil.x), tex->w - 1);
			draw.ty = (int)fmin(tex->h * (ceil.y - (int)ceil.y), tex->h - 1);
			draw.color = tex->data[draw.ty * tex->w + draw.tx];
			draw.color = (draw.color >> 1) & 8355711; // make a bit darker
			//disp->img.data[y * disp->w + x] =disp->ceil_color;
			disp->img.data[y * disp->w + x] = draw.color;	
			ceil.x += ceil_step.x;
			ceil.y += ceil_step.y;
		}
	}
}

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
	draw_floor(disp, player, &bg, &disp->tex[CONFIG_NO]);
	draw_ceil(disp, player, bg.ray_dir1, bg.ray_dir0, &disp->tex[CONFIG_SO]);
	return (0);
}
