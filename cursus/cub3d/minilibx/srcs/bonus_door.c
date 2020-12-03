#include "cub3d.h"

int	check_door_type(t_hit *hit_point, int map_data)
{
	if (map_data == MAP_WALL_VAL)
	{
		hit_point->door_type = MAP_WALL_VAL;
		return (1);
	}
	else if (map_data == MAP_OPDOOR_VAL)
	{
		hit_point->door_type = MAP_OPDOOR_VAL;
		return (1);
	}
	else if (map_data == MAP_SECRET_VAL)
	{
		hit_point->door_type = MAP_SECRET_VAL;
		return (1);
	}
	else if (map_data == MAP_CLDOOR_VAL)
	{
		hit_point->door_type = MAP_CLDOOR_VAL;
		return (1);
	}
	return (0);
}
