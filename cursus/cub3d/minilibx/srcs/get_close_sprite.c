#include "cub3d.h"

void	del_on_map_spr(t_map *map, t_spr spr)
{
	t_veci	idx;

	idx.y = (int)spr.pos.y;
	idx.x = (int)spr.pos.x;
	map->data[idx.y][idx.x] = MAP_ROAD_VAL;
} 

int		get_close_item(t_disp *disp, t_spr spr, int idx)
{
	int	ret;

	ret = idx;
	del_on_map_spr(&(disp->map), spr);
	lst_del_idx(&disp->spr_lst, ret);
	disp->spr_cnt = disp->spr_cnt - 1;
	ret -= 1;
	printf("You got an item!\n");
	return (ret);
}

int		get_close_attack(t_disp *disp, t_spr spr, int idx)
{
	int	ret;
	(void)disp;
	(void)spr;
	ret = idx;
	printf("You got an attack!\n");
	return (ret);
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
			if (spr.tex_nbr == CONFIG_ITEM)
				i = get_close_item(disp, spr, i);
		if (fabs(calc_dist(p->pos, spr.pos)) < ATTACK_APPROACH_DIST)
			if (spr.tex_nbr == CONFIG_S)
				i = get_close_attack(disp, spr, i);
	}	
}

