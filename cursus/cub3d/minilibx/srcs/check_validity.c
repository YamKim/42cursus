/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:46:20 by yekim             #+#    #+#             */
/*   Updated: 2020/12/28 15:14:57 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_color_range(int r, int g, int b)
{
	int	ret;

	ret = 0;
	if (!(r >= 0 && r <= 255))
		ret |= 1;
	if (!(g >= 0 && g <= 255))
		ret |= 1;
	if (!(b >= 0 && b <= 255))
		ret |= 1;
	return (ret);
}

int	is_number_arr(char **arr, int index_num, int type)
{
	int	k;
	int	i;

	k = -1;
	while (arr[++k])
	{
		i = -1;
		while (arr[k][++i])
			if (!(arr[k][i] >= 48 && arr[k][i] <= 57))
				return (ERR_PARSE);
	}
	if (index_num != k)
		return (ERR_PARSE);
	if (type == CONFIG_F || type == CONFIG_C)
		if (check_color_range(ft_atoi(arr[0]), ft_atoi(arr[1]),\
							ft_atoi(arr[2])))
			return (ERR_PARSE);
	return (0);
}

int	check_map_range(t_map map, int y, int x)
{
	int	ret;

	ret = 0;
	if (y <= 0 || y >= map.h - 1)
		ret = 1;
	else if (x <= 0 || map.data[y][x + 1] == MAP_BOARDER_VAL)
		ret = 1;
	else if (map.data[y - 1][x] == MAP_SPACE_VAL \
			|| map.data[y + 1][x] == MAP_SPACE_VAL)
		ret = 1;
	else if (map.data[y][x - 1] == MAP_SPACE_VAL\
			|| map.data[y][x + 1] == MAP_SPACE_VAL)
		ret = 1;
	return (ret);
}

int	is_map_valid(t_map map)
{
	int	y;
	int	x;
	int	ret;

	y = 0;
	ret = 0;
	while (y < map.h)
	{
		x = 0;
		while (map.data[y][x] != MAP_BOARDER_VAL)
		{
#if 0
			if (map.data[y][x] != MAP_ROAD_VAL ||
				map.data[y][x] == MAP_SPRITE_VAL)
#endif
			if (map.data[y][x] != MAP_WALL_VAL)
				ret |= check_map_range(map, y, x);
			if (map.data[y][x] == MAP_EXCEPTION_VAL)
				ret |= 1;
			++x;
		}
		++y;
	}
	return (ret);
}
