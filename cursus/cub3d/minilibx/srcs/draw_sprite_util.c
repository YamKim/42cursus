#include "cub3d.h"

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

t_vecd	set_sprite_scale(t_draw *draw, t_vecd coef, int tex_nbr)
{
	t_vecd	ret;
	
	draw->bias = (int)(SCALE_MOVE_SPRITE / coef.y);
	ret.y = SCALE_HDIV_SPRITE;
	ret.x = SCALE_WDIV_SPRITE;
	if (tex_nbr == TEXTURE_ITEM)
	{
		draw->bias = (int)(SCALE_MOVE_ITEM / coef.y);
		ret.y = SCALE_HDIV_ITEM;
		ret.x = SCALE_WDIV_ITEM;
	}
	if (tex_nbr == TEXTURE_ATTACK)
	{
		draw->bias = (int)(SCALE_MOVE_ATTACK / coef.y);
		ret.y = SCALE_HDIV_ATTACK;
		ret.x = SCALE_WDIV_ATTACK;
	}
	return (ret);
}

int		check_sprite_order(t_disp *disp, t_player *p, t_draw *draw, double *buf)
{
	int	ret;

	ret = p->coef.y > 0 && draw->x > 0 && draw->x < disp->w;
	ret &= p->coef.y < buf[draw->x];
	return (ret);
}
