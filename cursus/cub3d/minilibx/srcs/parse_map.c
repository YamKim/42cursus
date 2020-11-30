#include "cub3d.h"

void	init_map_info(t_map *map, int map_width, int map_height)
{
	int	j;
	int	i;

	map->pos_flag = 0;
	j = 0;
	while (j < map_height)
	{
		i = 0;
		while (i < map_width)
		{
			map->data[j][i] = 0;
			++i;
		}
		++j;
	}
}

void	set_map_sprite(t_disp *disp, int y, int x)
{
	disp->spr_buf[disp->spr_cnt].pos.y = y + 0.5;
	disp->spr_buf[disp->spr_cnt].pos.x = x + 0.5;
	disp->spr_buf[disp->spr_cnt].tex_nbr = CONFIG_S;
	disp->spr_cnt += 1;
}

void	set_map_player_pos(t_disp *disp, char orient, int y, int x)
{
	disp->map.pos_flag = 1; 
	disp->start_pos.y = y + 0.5;
	disp->start_pos.x = x + 0.5;
	disp->start_orient = orient;
}

int	get_map_element(t_disp *disp, char data, int y, int x)
{
	if (data == MAP_SPACE)
		return (MAP_SPACE_VAL);
	else if (data == MAP_ROAD)
		return (MAP_ROAD_VAL);
	else if (data == MAP_WALL)
		return (MAP_WALL_VAL);
	else if (data == MAP_SPRITE)
	{
		set_map_sprite(disp, y, x);
		return (MAP_SPRITE_VAL);
	}
	else if (data == NORTH || data == SOUTH || data == WEST || data == EAST)
	{
		if (disp->map.pos_flag)
			return (MAP_EXCEPTION_VAL);
		set_map_player_pos(disp, data, y, x);
		return (0);
	}
	return (MAP_EXCEPTION_VAL);
}

int	parse_map(t_disp *disp, char **map, int map_beg)
{
	int	y;
	int r;
	int	x;

	init_map_info(&(disp->map), MAX_NUM_MAP_WIDTH, MAX_NUM_MAP_HEIGHT);
	disp->spr_cnt = 0;
	r = map_beg + disp->map.height - 1;
	y = -1;
	while (++y < disp->map.height)
	{
		x = -1;
		while (map[r][++x])
			disp->map.data[y][x] = get_map_element(disp, map[r][x], y, x);
		disp->map.data[y][x] = MAP_BOARDER_VAL;
		--r;
	}
	if (is_map_valid(disp->map))
		return (ERR_PARSE_MAP);
	return (0);
}
