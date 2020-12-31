/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:22:40 by yekim             #+#    #+#             */
/*   Updated: 2020/12/31 10:29:12 by yekim            ###   ########.fr       */
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

static void		draw_ceil(t_disp *disp, t_bg *bg)
{
	bg->draw = set_background_draw(disp, 0);
	bg->draw.x = -1;
	while (++bg->draw.y <= bg->draw.yend)
	{
		bg->draw.x = -1;
		while (++bg->draw.x <= bg->draw.xend)
		{
			bg->draw.color = disp->ceil_color;
			disp->img.data[bg->draw.y * disp->w + bg->draw.x] = bg->draw.color;
		}
	}
}

static void		draw_floor(t_disp *disp, t_bg *bg)
{
	bg->draw = set_background_draw(disp, 1);
	bg->draw.x = -1;
	while (++bg->draw.y <= bg->draw.yend)
	{
		bg->draw.x = -1;
		while (++bg->draw.x <= bg->draw.xend)
		{
			bg->draw.color = disp->floor_color;
			disp->img.data[bg->draw.y * disp->w + bg->draw.x] = bg->draw.color;
		}
	}
}

int				draw_background(t_disp *disp, t_player *player)
{
	t_bg	bg;

	(void)player;
	draw_ceil(disp, &bg);
	draw_floor(disp, &bg);
	return (0);
}
