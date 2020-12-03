#include "cub3d.h"

void	show_map_data(t_disp disp)
{
	char	val;
	printf("MAP DATA========================================\n");
	printf("map_height: %d\n", disp.map.height);
	for (int j = 0; j < disp.map.height; ++j)
	{
		for (int i = 0; disp.map.data[j][i] != MAP_BOARDER_VAL; ++i)
		{
			if (disp.map.data[j][i] == MAP_ROAD_VAL)
				val = MAP_ROAD;
			if (disp.map.data[j][i] == MAP_WALL_VAL)
				val = MAP_WALL;
			if (disp.map.data[j][i] == MAP_SPACE_VAL)
				val = MAP_SPACE;
			if (disp.map.data[j][i] == MAP_ITEM_VAL)
				val = MAP_ITEM;
			if (disp.map.data[j][i] == MAP_EXCEPTION_VAL)
				val = 'X';
			if (disp.map.data[j][i] == MAP_BOARDER_VAL)
				val = 'H';
			printf("%c", val);
		}
		printf("\n");
	}
}

void	show_lst_data(t_lst *itr)
{
	int		idx;

	idx = 0;
	printf("LIST DATA===========================================\n");
	while (itr)
	{
		printf("idx: %2d, spr.pos.x: %6.2lf, spr.pos.y: %6.2lf\n", idx++, itr->spr.pos.x, itr->spr.pos.y);
		itr = itr->next;
	}
}

void	show_items(t_disp disp)
{
	int		idx;

	idx = 0;
	printf("LIST DATA===========================================\n");
	while (disp.itm_lst)
	{
		printf("idx: %2d, itm.pos.x: %6.2lf, itm.pos.y: %6.2lf\n", idx++, disp.itm_lst->itm.pos.x, disp.itm_lst->itm.pos.y);
		printf("disp->itm_cnt: %d\n", disp.itm_cnt);
		disp.itm_lst = disp.itm_lst->next;
	}
}
