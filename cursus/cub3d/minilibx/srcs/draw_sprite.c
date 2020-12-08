#include "cub3d.h"

double	*g_perp_buf;

void	set_sprite(t_disp *disp, t_pair *spr_pair, t_player *p)
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

t_draw	set_draw_sprite(t_disp *disp, t_vecd coef, int tex_nbr)
{
	int		spr_w;
	int		spr_h;
	t_vecd	scale;
	t_draw	ret;

	scale = set_sprite_scale(&ret, coef, tex_nbr);
	ret.xctr = (int)((double)disp->w / 2 * (1 + coef.x / coef.y));
	ret.yctr = (double)disp->h / 2 + ret.bias + disp->hctr_bias;
	spr_h = (int)fabs((double)disp->h / coef.y);
	ret.lh = spr_h / scale.x;
	ret.beg = (int)fmax(ret.yctr - (double)ret.lh / 2, 0.0);
	ret.end = (int)fmin(ret.yctr + (double)ret.lh / 2, disp->h - 1);
	spr_w = spr_h / scale.y;
	ret.xbeg = (int)fmax(ret.xctr - (double)spr_w / 2 , 0.0);
	ret.xend = (int)fmin(ret.xctr + (double)spr_w / 2 , disp->w - 1);
	ret.y = ret.beg;
	ret.x = ret.xbeg;
	return (ret);
}

void	draw_sprite_part(t_disp *disp, t_tex *tex, t_player *player, t_draw *draw)
{
	int	color;
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
					disp->img.data[draw->y * disp->w+ draw->x] = color;
			}
		}
		++(draw->x);
	}
}

int		draw_sprite(t_disp *disp, t_player *p, double *perp_buf)
{
	t_pair	*spr_pair;
	t_draw	draw;
	int		tex_nbr;
	int		i;

	g_perp_buf = perp_buf;
	get_close_sprite(disp, p);
	if (!(spr_pair = (t_pair *)malloc(sizeof(t_pair) * disp->spr_cnt)))
		return (ERR_MALLOC);
	set_sprite(disp, spr_pair, p);
	sort_spr_pair(spr_pair, disp->spr_cnt);
	i = -1;
	while (++i < disp->spr_cnt)
	{
		p->coef = get_coef_spr(p, &(spr_pair[i]), disp->spr_lst);
		tex_nbr = lst_get_idx(disp->spr_lst, spr_pair[i].ord)->spr.tex_nbr;
		draw = set_draw_sprite(disp, p->coef, tex_nbr); 
		draw_sprite_part(disp, &(disp->tex[tex_nbr]), p, &draw);
	}
	free(spr_pair);
	return (1);
}
