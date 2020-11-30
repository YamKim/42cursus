#include "cub3d.h"

void	show_map_data(t_disp disp)
{
	char	val;
	printf("map_height: %d\n", disp.map.height);
	for (int j = 0; j < disp.map.height; ++j)
	{
		for (int i = 0; i < MAX_NUM_MAP_WIDTH; ++i)
		{
			if (disp.map.data[j][i] == MAP_ROAD_VAL)
				val = MAP_ROAD;
			if (disp.map.data[j][i] == MAP_WALL_VAL)
				val = MAP_WALL;
			if (disp.map.data[j][i] == MAP_SPACE_VAL)
				val = MAP_SPACE;
			if (disp.map.data[j][i] == MAP_EXCEPTION_VAL)
				val = 'X';
			if (disp.map.data[j][i] == MAP_BOARDER_VAL)
				val = 'H';
			printf("%c", val);
		}
		printf("\n");
	}
}
