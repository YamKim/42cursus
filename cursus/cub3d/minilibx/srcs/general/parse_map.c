/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:01:18 by yekim             #+#    #+#             */
/*   Updated: 2020/12/31 18:08:00 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	set_map_sprite(t_disp *disp, int y, int x, char data)
{
	t_spr	spr;
	t_lst	*tmp;
	int		ret;

	spr.pos.y = y + 0.5;
	spr.pos.x = x + 0.5;
	ret = set_animation(disp, &spr, data);
	tmp = lst_new_spr(spr);
	lst_add_back(&(disp->spr_lst), tmp);
	disp->spr_cnt += 1;
	return (ret);
}

static int	set_map_player(t_disp *disp, char orient, int y, int x)
{
	disp->start_pos.y = y + 0.5;
	disp->start_pos.x = x + 0.5;
	disp->start_orient = orient;
	return (MAP_ROAD_VAL);
}

static int	get_map_element(t_disp *disp, char data, int y, int x)
{
	if (data == MAP_SPACE)
		return (MAP_SPACE_VAL);
	else if (data == MAP_ROAD)
		return (MAP_ROAD_VAL);
	else if (data == MAP_WALL)
		return (MAP_WALL_VAL);
	else if (data == MAP_SPRITE)
		return (set_map_sprite(disp, y, x, data));
	else if (data == NORTH || data == SOUTH || data == WEST || data == EAST)
	{
		if (disp->start_pos.x >= 0 && disp->start_pos.y >= 0)
			return (MAP_EXCEPTION_VAL);
		return (set_map_player(disp, data, y, x));
	}
	return (MAP_EXCEPTION_VAL);
}

int			parse_map(t_disp *disp, char **map, int map_beg)
{
	int	y;
	int r;
	int	x;

	r = map_beg + disp->map.h - 1;
	y = -1;
	while (++y < disp->map.h)
	{
		x = -1;
		while (map[r][++x])
			disp->map.data[y][x] = get_map_element(disp, map[r][x], y, x);
		if (x == 0 || x >= disp->map.max_w)
			disp->map.max_w = x;
		disp->map.data[y][x] = MAP_BOARDER_VAL;
		--r;
	}
	if (is_map_valid(disp->map))
		return (ERR_PARSE_MAP);
	return (0);
}
