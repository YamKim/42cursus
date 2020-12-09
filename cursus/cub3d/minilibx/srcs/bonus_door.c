#include "cub3d.h"

int	case_secret_door(int map_data)
{
	int	ret;

	ret = 0;
	if (map_data == MAP_WALL_VAL)
		ret = MAP_WALL_VAL;
	else if (map_data == MAP_SECRET_VAL)
		ret = MAP_SECRET_VAL;
	return (ret);
}

int	case_general_wall(int map_data)
{
	int	ret;

	ret = 0;
	if (map_data == MAP_WALL_VAL)
		ret = MAP_WALL_VAL;
	else if (map_data == MAP_SECRET_VAL)
		ret = MAP_ROAD_VAL;
	return (ret);
}

int	check_door_type(t_hit *hit_point, int map_data)
{
	int	ret;

	ret = 0;
	if (hit_point->secret_door)
		hit_point->door_type = case_secret_door(map_data);	
	else
		hit_point->door_type = case_general_wall(map_data);
	if (hit_point->door_type >= 1)
		ret = 1;
	return (ret);
}
