#include "cub3d.h"

void	init_map_info(t_disp *disp, int map_width, int map_height)
{
	int	j;
	int	i;

	disp->spr_cnt = 0;
	disp->map.pos_flag = 0;
	j = -1;
	while (++j < map_height)
	{
		i = -1;
		while (++i < map_width)
			disp->map.data[j][i] = MAP_UNUSED_VAL;
	}
}

void	set_map_sprite(t_disp *disp, int y, int x, char data)
{
	t_spr	spr;
	t_lst	*tmp;

	spr.pos.y = y + 0.5;
	spr.pos.x = x + 0.5;
	if (data == MAP_SPRITE)
		spr.tex_nbr = CONFIG_S;
	else if (data == MAP_ITEM)
		spr.tex_nbr = CONFIG_ITEM;
	else if (data == MAP_ATTACK)
		spr.tex_nbr = CONFIG_ATTACK;
	tmp = lst_new_spr(spr);
	lst_add_back(&(disp->spr_lst), tmp);
	disp->spr_cnt += 1;
}


void	set_map_player_pos(t_disp *disp, char orient, int y, int x)
{
	disp->map.pos_flag = 1; 
	disp->start_pos.y = y + 0.5;
	disp->start_pos.x = x + 0.5;
	disp->start_orient = orient;
}

int	get_map_element_bonus(t_disp *disp, char data, int y, int x)
{
	if (data == MAP_SECRET)
		return (MAP_SECRET_VAL);
	else if (data == MAP_CLDOOR)
		return (MAP_CLDOOR_VAL);
	else if (data == MAP_OPDOOR)
		return (MAP_OPDOOR_VAL);
	else if (data == MAP_ITEM)
	{
		set_map_sprite(disp, y, x, data);
		return (MAP_ITEM_VAL);
	}
	else if (data == MAP_ATTACK)
	{
		set_map_sprite(disp, y, x, data);
		return (MAP_ATTACK_VAL);
	}
	return (MAP_EXCEPTION_VAL);
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
		set_map_sprite(disp, y, x, data);
		return (MAP_SPRITE_VAL);
	}
	else if (data == NORTH || data == SOUTH || data == WEST || data == EAST)
	{
		if (disp->map.pos_flag)
			return (MAP_EXCEPTION_VAL);
		set_map_player_pos(disp, data, y, x);
		return (0);
	}
	return (get_map_element_bonus(disp, data, y, x));
}

int	parse_map(t_disp *disp, char **map, int map_beg)
{
	int	y;
	int r;
	int	x;

	init_map_info(disp, MAX_NUM_MAP_WIDTH, MAX_NUM_MAP_HEIGHT);
	init_bonus_info(disp);
	r = map_beg + disp->map.h - 1;
	y = -1;
	while (++y < disp->map.h)
	{
		x = -1;
		while (map[r][++x])
			disp->map.data[y][x] = get_map_element(disp, map[r][x], y, x);
		if (x >= disp->map.max_w)
			disp->map.max_w = x;
		disp->map.data[y][x] = MAP_BOARDER_VAL;
		--r;
	}
	if (is_map_valid(disp->map))
		return (ERR_PARSE_MAP);
	return (0);
}
