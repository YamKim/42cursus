/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setting2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 09:05:24 by yekim             #+#    #+#             */
/*   Updated: 2020/12/31 09:41:36 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_img	set_skybox_img(const t_disp *disp)
{
	t_img	ret;
	int		tmp;

	ret.w = disp->w * DISP2SKYW;
	ret.h = disp->h * DISP2SKYH;
	ret.ptr = mlx_new_image(disp->mlx_ptr, ret.w, ret.h);
	ret.data = (int *)mlx_get_data_addr(ret.ptr, &tmp, &tmp, &tmp);
	return (ret);
}

static t_img	set_hud_img(
				const t_disp *disp,
				const double scale_y,
				const double scale_x)
{
	t_img	ret;
	int		tmp;

	ret.w = (int)disp->w * scale_x;
	ret.h = (int)disp->h * scale_y;
	ret.ptr = mlx_new_image(disp->mlx_ptr, ret.w, ret.h);
	ret.data = (int *)mlx_get_data_addr(ret.ptr, &tmp, &tmp, &tmp);
	return (ret);
}

void			init_setting_bonus(t_disp *disp)
{
	disp->skybox = set_skybox_img(disp);
	disp->hud[0] = set_hud_img(disp, DISP2HUD_LIFE_H, DISP2HUD_LIFE_W);
	disp->hud[1] = set_hud_img(disp, DISP2HUD_ITEM_H, DISP2HUD_ITEM_W);
	disp->hud[2] = set_hud_img(disp, DISP2HUD_ITEM_H, DISP2HUD_ITEM_W);
}
