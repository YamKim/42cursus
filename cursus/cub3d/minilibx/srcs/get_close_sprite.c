#include "cub3d.h"

void	del_on_map_spr(t_map *map, t_spr *spr)
{
	t_veci	idx;

	idx.y = (int)spr->pos.y;
	idx.x = (int)spr->pos.x;
	map->data[idx.y][idx.x] = MAP_ROAD_VAL;
} 

int		get_close_item(t_disp *disp, t_player *player, t_spr *spr, int idx)
{
	int	ret;

	ret = idx;
	del_on_map_spr(&(disp->map), spr);
	lst_del_idx(&disp->spr_lst, ret);
	disp->spr_cnt = disp->spr_cnt - 1;
	ret -= 1;
	player->clk[TIC_ITEM].beg = clock();
	printf("You got an item!\n");
	player->life += 1;
	printf("life: %d\n", player->life);
	return (ret);
}

int		get_close_attack(t_disp *disp, t_player *player, int idx)
{
	int	ret;
	int	i;

	ret = idx;
	player->clk[TIC_ATTACK].beg = clock();
	printf("You got an attack!\n");
	i = -1;
	while (++i < ATTACK_PUSH_BACK)
		move_backward(player, disp->map);
	player->life -= 1;
	printf("life: %d\n", player->life);
	return (ret);
}


void	get_close_sprite(t_disp *disp, t_player *p)
{
	int		i;
	t_spr	*spr;

	i = -1;
	while (++i < disp->spr_cnt)
	{
		spr = &(lst_get_idx(disp->spr_lst, i)->spr);
		if (fabs(calc_dist(p->pos, spr->pos)) < APPROACH_ITEM_DIST)
			if (spr->tex_nbr == TEXTURE_ITEM)
				i = get_close_item(disp, p, spr, i);
		if (fabs(calc_dist(p->pos, spr->pos)) < APPROACH_ATTACK_DIST)
			if (spr->tex_nbr == TEXTURE_ATTACK)
				i = get_close_attack(disp, p, i);
	}	
}

