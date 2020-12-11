#include "cub3d.h"

void	show_map_data(t_disp disp)
{
	char	val;
	printf("MAP DATA========================================\n");
	printf("max_width: %d\n", disp.map.max_w);
	printf("height: %d\n", disp.map.h);
	for (int j = disp.map.h - 1; j >= 0; --j)
	{
		for (int i = 0; disp.map.data[j][i] != MAP_BOARDER_VAL; ++i)
		{
			if (disp.map.data[j][i] == MAP_ROAD_VAL)
				val = MAP_ROAD;
			if (disp.map.data[j][i] == MAP_WALL_VAL)
				val = MAP_WALL;
			if (disp.map.data[j][i] == MAP_SPACE_VAL)
				val = MAP_SPACE;
			if (disp.map.data[j][i] == MAP_SPRITE_VAL)
				val = MAP_SPRITE;
			if (disp.map.data[j][i] == MAP_ITEM_VAL)
				val = MAP_ITEM;
			if (disp.map.data[j][i] == MAP_SECRET_VAL)
				val = MAP_SECRET;
			if (disp.map.data[j][i] == MAP_CLDOOR_VAL)
				val = MAP_CLDOOR;
			if (disp.map.data[j][i] == MAP_OPDOOR_VAL)
				val = MAP_OPDOOR;
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
