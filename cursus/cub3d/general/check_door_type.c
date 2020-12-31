/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:39:48 by yekim             #+#    #+#             */
/*   Updated: 2020/12/31 18:06:39 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	case_general_wall(const int map_data)
{
	int	ret;

	ret = 0;
	if (map_data == MAP_WALL_VAL)
		ret = MAP_WALL_VAL;
	return (ret);
}

int			check_door_type(
			t_hit *hit_point,
			const int map_data)
{
	int	ret;

	ret = 0;
	if (hit_point->secret_door == 0)
		hit_point->door_type = case_general_wall(map_data);
	if (hit_point->door_type >= 1)
		ret = 1;
	return (ret);
}
