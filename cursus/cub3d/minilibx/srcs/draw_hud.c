/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:44:59 by yekim             #+#    #+#             */
/*   Updated: 2020/12/22 13:36:24 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_hud_img(t_img *hud)
{
	int	y;
	int	x;

	x = -1;
	while (++x < hud->w)
	{
		y = -1;
		while (++y < hud->h)
			hud->data[y * hud->w + x] = 0xFF000000;
	}
}

t_draw	set_hud_draw(t_img *hud)
{
	t_draw	ret;

	ret.xctr = (int)((double)hud->w / 2);
	ret.yctr = (int)((double)hud->h / 2);
	ret.lh = hud->h;
	ret.xbeg = (int)fmax(ret.xctr - (double)hud->w / 2, 0);
	ret.xend = (int)fmin(ret.xctr + (double)hud->w / 2, hud->w - 1);
	ret.ybeg = (int)fmax(ret.yctr - (double)hud->h / 2, 0);
	ret.yend = (int)fmin(ret.yctr + (double)hud->h / 2, hud->h - 1);
	return (ret);
}

t_img	set_hud_img(t_disp *disp, t_vecd scale)
{
	t_img	ret;
	int		tmp;

	ret.w = (int)disp->w * scale.x;
	ret.h = (int)disp->h * scale.y;
	ret.ptr = mlx_new_image(disp->mlx_ptr, ret.w, ret.h);
	ret.data = (int *)mlx_get_data_addr(ret.ptr, &tmp, &tmp, &tmp);
	return (ret);
}

void	draw_hud_part(t_img *hud, t_draw *draw, t_tex tex)
{
	t_vecd	tpos;
	t_vecd	step;

	step.x = (double)tex.w / hud->w;
	step.y = (double)tex.h / hud->h;
	draw->x = draw->xbeg - 1;
	while (++(draw->x) < draw->xend)
	{
		tpos.x = draw->x - draw->xctr + (double)hud->w / 2;
		draw->tx = (int)fmin(tpos.x * step.x, tex.w - 1);
		draw->y = draw->ybeg - 1;
		while (++(draw->y) < draw->yend)
		{
			tpos.y = draw->y - draw->yctr + (double)hud->h / 2;
			draw->ty = (int)fmin(tpos.y * step.y, tex.h - 1);
			draw->color = tex.data[draw->ty * tex.w + draw->tx];
			hud->data[draw->y * hud->w + draw->x] = draw->color;
		}
	}
}

int		draw_hud(t_disp *dp, t_tex tex, t_vecd scale, t_veci bias)
{
	t_img	hud;
	t_draw	draw;

	hud = set_hud_img(dp, scale);
	init_hud_img(&hud);
	draw = set_hud_draw(&hud);
	draw_hud_part(&hud, &draw, tex);
	bias.y -= (int)((double)hud.h / 2);
	bias.x -= (int)((double)hud.w / 2);
	mlx_put_image_to_window(dp->mlx_ptr, dp->win_ptr, \
							hud.ptr, bias.x, bias.y);
	return (0);
}
