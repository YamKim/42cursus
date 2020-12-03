#include "cub3d.h"

double	*g_perp_buf;

void	set_sprite(t_disp *disp, t_pair *spr_pair, t_player *p)
{
	int		i;
	t_spr	spr;

	i = 0;
	while (i < disp->spr_cnt)
	{
		spr = lst_get_idx(disp->spr_lst, i)->spr;
		spr_pair[i].ord = i;
		spr_pair[i].dist = calc_dist(p->pos, spr.pos);
		++i;
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

void	sort_spr_pair(t_pair *spr_pair, int spr_cnt)
{
	int		i;
	int		j;
	double	tmp_dist;
	int		tmp_ord;

	i = 1;
	while (i < spr_cnt)
	{
		tmp_dist = spr_pair[i].dist;
		j = i;
		while (--j >= 0 && tmp_dist > spr_pair[j].dist)
		{
			spr_pair[j + 1].dist = spr_pair[j].dist;
			spr_pair[j].dist = tmp_dist;
			tmp_ord = spr_pair[j].ord;
			spr_pair[j].ord = spr_pair[j + 1].ord;
			spr_pair[j + 1].ord = tmp_ord;
		}
		++i;
	}
}

void	set_draw_sprite(t_disp disp, t_draw *draw, double y_dist)
{
	int	h;
	int	w;
	int spr_w;
	int	spr_h;

	draw->bias = 0;
	h = disp.h;
	w = disp.w;
	spr_h = (int)fabs((double)h / y_dist);
	draw->lh = spr_h;
	draw->beg = (int)fmax((double)(h - draw->lh) / 2, 0.0);
	draw->end = (int)fmin((double)(h + draw->lh) / 2, h - 1);
	spr_w = spr_h;
	draw->xbeg = (int)fmax((double)draw->xctr - (double)spr_w / 2 , 0.0);
	draw->xend = (int)fmin((double)draw->xctr + (double)spr_w / 2 , w - 1);
	draw->y = draw->beg;
	draw->x = draw->xbeg;
}

void	draw_sprite_part(t_disp *disp, t_tex *tex, t_player *player, t_draw *draw)
{
	int	tmp;
	int	color;

	while (draw->x < draw->xend)
	{
		draw->tx = (int)((256 * (draw->x - draw->xctr + draw->lh / 2) \
							* tex->w / draw->lh) / 256);
		if(player->coef.y > 0 && draw->x > 0 && draw->x < disp->w\
			&& player->coef.y < g_perp_buf[draw->x])
		{
			draw->y = draw->beg - 1;
			while (++(draw->y) < draw->end)
			{
				tmp = (draw->y * 2 - disp->h+ draw->lh) * 128;
				draw->ty = ((tmp * tex->h) / draw->lh) / 256;
				color = tex->data[draw->ty * tex->w + draw->tx];
				if((color & 0x00FFFFFF) != 0)
					disp->img.data[draw->y * disp->w+ draw->x] = color;
			}
		}
		++(draw->x);
	}
}

int		draw_sprite(t_disp disp, t_player p, t_hit hit_point, double *perp_buf)
{
	t_pair	*spr_pair;
	t_draw	draw;
	int		tex_nbr;
	int		i;

	g_perp_buf = perp_buf;
	if (!(spr_pair = (t_pair *)malloc(sizeof(t_pair) * disp.spr_cnt)))
		return (ERR_MALLOC);
	set_sprite(&disp, spr_pair, &p);
	sort_spr_pair(spr_pair, disp.spr_cnt);
	i = -1;
	while (++i < disp.spr_cnt)
	{
		p.coef = get_coef_spr(&p, &(spr_pair[i]), disp.spr_lst);
		draw.xctr = (int)((double)disp.w / 2 * (1 + p.coef.x / p.coef.y));
		set_draw_sprite(disp, &draw, p.coef.y); 
		tex_nbr = lst_get_idx(disp.spr_lst, spr_pair[i].ord)->spr.tex_nbr;
		draw_sprite_part(&disp, &(disp.tex[tex_nbr]), &p, &draw);
	}
	free(spr_pair);
	return (1);
}
