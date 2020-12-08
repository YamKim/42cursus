#include "cub3d.h"

double	*g_perp_buf;

void	set_item(t_disp *disp, t_pair *itm_pair, t_player *p)
{
	int		i;
	t_itm	itm;

	i = -1;
	while (++i < disp->itm_cnt)
	{
		itm = lst_get_idx(disp->itm_lst, i)->itm;
		itm_pair[i].ord = i;
		itm_pair[i].dist = calc_dist(p->pos, itm.pos);
	}	
}

t_vecd	get_coef_item(t_player *p, t_pair *itm_pair, t_lst *itm_lst)
{
	t_vecd	ret;
	double	det;
	t_itm	itm;
	t_vecd	itm_dist;

	itm = lst_get_idx(itm_lst, itm_pair->ord)->itm;
	itm_dist.x = itm.pos.x - p->pos.x;
	itm_dist.y = itm.pos.y - p->pos.y;
	det = calc_det(p->plane, p->dir);
	ret.x = (p->dir.y * itm_dist.x - p->dir.x * itm_dist.y) / det;
	ret.y = (-p->plane.y * itm_dist.x + p->plane.x * itm_dist.y) / det;
	return (ret);
}

void	sort_item_pair(t_pair *itm_pair, int itm_cnt)
{
	int		i;
	int		j;
	double	tmp_dist;
	int		tmp_ord;

	i = 1;
	while (i < itm_cnt)
	{
		tmp_dist = itm_pair[i].dist;
		j = i;
		while (--j >= 0 && tmp_dist > itm_pair[j].dist)
		{
			itm_pair[j + 1].dist = itm_pair[j].dist;
			itm_pair[j].dist = tmp_dist;
			tmp_ord = itm_pair[j].ord;
			itm_pair[j].ord = itm_pair[j + 1].ord;
			itm_pair[j + 1].ord = tmp_ord;
		}
		++i;
	}
}

t_draw	set_draw_item(t_disp *disp, t_vecd coef)
{
	int		h;
	int		w;
	int		itm_w;
	int		itm_h;
	t_draw	ret;

	h = disp->h;
	w = disp->w;
	ret.bias = (int)(ITEM_MOVE/ coef.y);
	ret.xctr = (int)((double)disp->w / 2 * (1 + coef.x / coef.y));
	ret.yctr = (double)disp->h / 2 + ret.bias + disp->hctr_bias;
	itm_h = (int)(fabs((double)h / coef.y));
	ret.lh = itm_h / ITEM_VDIV;
	ret.beg = (int)fmax(ret.yctr - (double)ret.lh / 2, 0.0);
	ret.end = (int)fmin(ret.yctr + (double)ret.lh / 2, h - 1);
	itm_w = itm_h / ITEM_UDIV;
	ret.xbeg = (int)fmax(ret.xctr - (double)itm_w / 2, 0.0);
	ret.xend = (int)fmin(ret.xctr + (double)itm_w / 2, w - 1);
	ret.y = ret.beg;
	ret.x = ret.xbeg;
	return (ret);
}

void	draw_item_part(t_disp *disp, t_tex *tex, t_player *player, t_draw *draw)
{
	int		color;
	double	tmp_ypos;
	double	tmp_xpos;

	while (draw->x < draw->xend)
	{
		tmp_xpos = draw->x - draw->xctr + (double)draw->lh / 2;
		draw->tx = (int)fmin((tmp_xpos * tex->w / draw->lh), tex->w - 1);
		if(player->coef.y > 0 && draw->x > 0 && draw->x < disp->w \
			&& player->coef.y < g_perp_buf[draw->x])
		{
			draw->y = draw->beg - 1;
			while (++(draw->y) < draw->end)
			{
				tmp_ypos = draw->y - draw->yctr + (double)draw->lh / 2;
				draw->ty = (int)fmin(tmp_ypos * tex->h / draw->lh, tex->h - 1);
				color = tex->data[draw->ty * tex->w + draw->tx];
				if((color & 0x00FFFFFF) != 0)
					disp->img.data[draw->y * disp->w + draw->x] = color;
			}
		}
		++(draw->x);
	}
}

int		draw_item(t_disp *disp, t_player *p, double *perp_buf)
{
	t_pair	*itm_pair;
	t_draw	draw;
	int		tex_nbr;
	int		i;

	g_perp_buf = perp_buf;
	get_close_item(disp, p);
	if (!(itm_pair = (t_pair *)malloc(sizeof(t_pair) * disp->itm_cnt)))
		return (ERR_MALLOC);
	set_item(disp, itm_pair, p);
	sort_item_pair(itm_pair, disp->itm_cnt);
	i = -1;
	while (++i < disp->itm_cnt)
	{
		p->coef = get_coef_item(p, &(itm_pair[i]), disp->itm_lst);
		draw = set_draw_item(disp, p->coef); 
		tex_nbr = lst_get_idx(disp->itm_lst, itm_pair[i].ord)->itm.tex_nbr;
		draw_item_part(disp, &(disp->tex[tex_nbr]), p, &draw);
	}
	free(itm_pair);
	return (1);
}
