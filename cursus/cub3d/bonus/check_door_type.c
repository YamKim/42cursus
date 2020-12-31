/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:39:48 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 13:40:35 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	case_secret_door(const int map_data)
{
	int	ret;

	ret = 0;
	if (map_data == MAP_WALL_VAL)
		ret = MAP_WALL_VAL;
	else if (map_data == MAP_SECRET_VAL)
		ret = MAP_SECRET_VAL;
	else if (map_data == MAP_CLDOOR_VAL)
		ret = MAP_CLDOOR_VAL;
	else if (map_data == MAP_OPDOOR_VAL)
		ret = MAP_OPDOOR_VAL;
	return (ret);
}

static int	case_general_wall(const int map_data)
{
	int	ret;

	ret = 0;
	if (map_data == MAP_WALL_VAL)
		ret = MAP_WALL_VAL;
	else if (map_data == MAP_SECRET_VAL)
		ret = MAP_ROAD_VAL;
	else if (map_data == MAP_CLDOOR_VAL)
		ret = MAP_CLDOOR_VAL;
	else if (map_data == MAP_OPDOOR_VAL)
		ret = MAP_ROAD_VAL;
	return (ret);
}

int			check_door_type(
			t_hit *hit_point,
			const int map_data)
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
