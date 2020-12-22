/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:48:52 by yekim             #+#    #+#             */
/*   Updated: 2020/12/21 12:11:46 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	*g_perp_buf;

void	set_spr_pair(t_disp *disp, t_pair *spr_pair, t_player *p)
{
	int		i;
	t_spr	spr;

	i = -1;
	while (++i < disp->spr_cnt)
	{
		spr = lst_get_idx(disp->spr_lst, i)->spr;
		spr_pair[i].ord = i;
		spr_pair[i].dist = calc_dist(p->pos, spr.pos);
	}
}

t_vecd	get_coef_spr(t_player *p, t_pair *spr_pair, t_lst *spr_lst)
{
	t_vecd	ret;
	double	det;
	t_spr	spr;
	t_vecd	spr_dist;

	spr = lst_get_idx(spr_lst, spr_pair->ord)->spr;
	spr_dist.x = spr.pos.x - p->pos.x;
	spr_dist.y = spr.pos.y - p->pos.y;
	det = calc_det(p->plane, p->dir);
	ret.x = (p->dir.y * spr_dist.x - p->dir.x * spr_dist.y) / det;
	ret.y = (-p->plane.y * spr_dist.x + p->plane.x * spr_dist.y) / det;
	return (ret);
}

t_draw	set_sprite_draw(t_disp *disp, t_vecd coef, int tex_nbr)
{
	int		spr_w;
	int		spr_h;
	t_vecd	scale;
	t_draw	ret;

	scale = set_sprite_scale(&ret, coef, tex_nbr);
	ret.xctr = (int)((double)disp->w / 2 * (1 + coef.x / coef.y));
	ret.yctr = (int)((double)disp->h / 2 + ret.bias + disp->hctr_bias);
	spr_h = (int)fabs((double)disp->h / coef.y);
	ret.lh = spr_h * scale.x;
	ret.ybeg = (int)fmax(ret.yctr - (double)ret.lh / 2, 0.0);
	ret.yend = (int)fmin(ret.yctr + (double)ret.lh / 2, disp->h - 1);
	spr_w = spr_h * scale.y;
	ret.xbeg = (int)fmax(ret.xctr - (double)spr_w / 2, 0.0);
	ret.xend = (int)fmin(ret.xctr + (double)spr_w / 2, disp->w - 1);
	ret.x = ret.xbeg;
	return (ret);
}

void	draw_sprite_part(t_disp *disp, t_tex *tex, t_player *p, t_draw *draw)
{
	t_vecd	tpos;
	t_vecd	step;

	step.x = (double)tex->w / draw->lh;
	step.y = (double)tex->h / draw->lh;
	draw->x = draw->xbeg - 1;
	while (++(draw->x) <= draw->xend)
	{
		tpos.x = draw->x - draw->xctr + (double)draw->lh / 2;
		draw->tx = (int)fmin(tpos.x * step.x, tex->w - 1);
		if (check_order(disp, p, draw, g_perp_buf))
		{
			draw->y = draw->ybeg;
			while (++(draw->y) < draw->yend)
			{
				tpos.y = draw->y - draw->yctr + (double)draw->lh / 2;
				draw->ty = (int)fmin(tpos.y * step.y, tex->h - 1);
				draw->color = tex->data[draw->ty * tex->w + draw->tx];
				if ((draw->color & 0x00FFFFFF) != 0)
					disp->img.data[draw->y * disp->w + draw->x] = draw->color;
			}
		}
	}
}

int		draw_sprite(t_disp *disp, t_player *p, double *perp_buf)
{
	t_pair	*spr_pair;
	t_draw	draw;
	int		i;
	t_spr	*spr;

	g_perp_buf = perp_buf;
	get_close_sprite(disp, p);
	if (!(spr_pair = (t_pair *)malloc(sizeof(t_pair) * disp->spr_cnt)))
		return (ERR_MALLOC);
	set_spr_pair(disp, spr_pair, p);
	sort_spr_pair(spr_pair, disp->spr_cnt);
	i = -1;
	while (++i < disp->spr_cnt)
	{
		p->coef = get_coef_spr(p, &(spr_pair[i]), disp->spr_lst);
		spr = &(lst_get_idx(disp->spr_lst, spr_pair[i].ord)->spr);
		draw = set_sprite_draw(disp, p->coef, spr->tex_nbr);
		draw_sprite_part(disp, spr->tex, p, &draw);
		animate_sprite(spr);
	}
	free(spr_pair);
	return (1);
}
