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

void	del_on_map_spr(t_map *map, t_spr spr)
{
	t_veci	idx;

	idx.y = (int)spr.pos.y;
	idx.x = (int)spr.pos.x;
	map->data[idx.y][idx.x] = MAP_ROAD_VAL;
} 

void	get_close_sprite(t_disp *disp, t_player *p)
{
	int		i;
	t_spr	spr;

	i = -1;
	while (++i < disp->spr_cnt)
	{
		spr = lst_get_idx(disp->spr_lst, i)->spr;
		if (fabs(calc_dist(p->pos, spr.pos)) < ITEM_APPROACH_DIST)
		{
			if (spr.tex_nbr == CONFIG_ITEM)
			{
				del_on_map_spr(&(disp->map), spr);
				lst_del_idx(&disp->spr_lst, i);
				disp->spr_cnt = disp->spr_cnt - 1;
				--i;
				printf("You got an item!\n");
			}
		}
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
	return (ret);
}

