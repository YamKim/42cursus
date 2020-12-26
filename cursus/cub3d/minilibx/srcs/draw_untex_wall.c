/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_untex_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:40:46 by yekim             #+#    #+#             */
/*   Updated: 2020/12/26 12:53:52 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		get_untex_wall_color(const t_hit *hit_point)
{
	int	ret;

	ret = 152 << 16 | 102 << 8 | 51;
	if (hit_point->side == 1)
		ret /= 2;
	return (ret);
}

static void		set_draw_untex_wall(
				t_disp *disp,
				t_draw *draw,
				const t_hit *hit_point)
{
	if (fabs(hit_point->perp_wall_dist - 0.0) < EPSILON)
		draw->lh = (int)(disp->h * 2);
	else
		draw->lh = (int)(disp->h / hit_point->perp_wall_dist);
	draw->ybeg = (int)fmax((((double)disp->h - draw->lh) / 2), 0);
	draw->yend = (int)fmin((((double)disp->h + draw->lh) / 2), disp->h - 1);
	draw->y = 0;
}

/*
** @ function name: draw_line
** @ input parameter:
**			1. image data
**			2. index for screen width
**			3. information about hit to use perp_wall_dist and color
** @ output:
** @ return :
** @ brief  : draw lines which is calculated by perp_wall_dist on screen.
** @ warning:
*/

void			draw_untex_wall(
				t_disp *disp,
				t_player *player,
				const int x,
				const t_hit *hp)
{
	t_draw	draw;

	(void)player;
	set_draw_untex_wall(disp, &draw, hp);
	while (draw.y < draw.ybeg)
		disp->img.data[(draw.y++) * disp->w + x] = disp->ceil_color;
	draw.y = draw.ybeg;
	while (draw.y < draw.yend)
		disp->img.data[(draw.y++) * disp->w + x] = get_untex_wall_color(hp);
	while (draw.y < disp->h)
		disp->img.data[(draw.y++) * disp->w + x] = disp->floor_color;
}
