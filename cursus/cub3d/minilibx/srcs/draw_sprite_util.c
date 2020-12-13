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
	
	draw->bias = (int)(SPRITE_MOVE / coef.y);
	ret.y = SPRITE_VDIV;
	ret.x = SPRITE_UDIV;
	if (tex_nbr == CONFIG_ITEM)
	{
		draw->bias = (int)(ITEM_MOVE / coef.y);
		ret.y = ITEM_VDIV;
		ret.x = ITEM_UDIV;
	}
	if (tex_nbr >= CONFIG_A0 && tex_nbr <= CONFIG_A4)
	{
		draw->bias = (int)(ATTACK_MOVE / coef.y);
		ret.y = ATTACK_VDIV;
		ret.x = ATTACK_UDIV;
	}
	return (ret);
}

