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

int	get_element(t_disp *disp, char data, int y, int x)
{
	if (data == MAP_SPACE)
		return (MAP_SPACE_VAL);
	else if (data == MAP_ROAD)
		return (MAP_ROAD_VAL);
	else if (data == MAP_WALL)
		return (MAP_WALL_VAL);
	else if (data == MAP_SPRITE)
	{
		disp->spr_buf[disp->spr_cnt].pos.y = y + 0.5;
		disp->spr_buf[disp->spr_cnt].pos.x = x + 0.5;
		disp->spr_buf[disp->spr_cnt].tex_nbr = CONFIG_S;
		disp->spr_cnt += 1;
		return (MAP_SPRITE_VAL);
	}
	else if (data == NORTH || data == SOUTH || data == WEST || data == EAST)
	{
		if (disp->map.pos_flag)
			return (ERR_PARSE_MAP);
		disp->map.pos_flag = 1; 
		disp->start_pos.y = y + 0.5;
		disp->start_pos.x = x + 0.5;
		disp->start_orient = data;
		return (0);
	}
	return (MAP_EXCEPTION_VAL);
}

int	get_map_data(t_disp *disp, char **map, int map_beg)
{
	int	y;
	int r;
	int	x;
	int	ret;

	init_map_info(&(disp->map), MAX_NUM_MAP_WIDTH, MAX_NUM_MAP_HEIGHT);
	disp->spr_cnt = 0;
	r = map_beg + disp->map.height - 1;
	y = 0;
	while (y < disp->map.height)
	{
		x = 0;
		while (map[r][x])
		{
			disp->map.data[y][x] = get_element(disp, map[r][x], y, x);
			++x;
		}
		disp->map.data[y][x] = MAP_BOARDER_VAL;
		++y;
		--r;
	}
	ret = 0;
	if (disp->map.pos_flag != 1)
		ret |= ERR_PARSE_MAP;
	if (is_map_valid(disp->map))
		ret |= ERR_PARSE_MAP;
	return (ret);
}

// over max resolution -> max resolution
/*
** lb: line_buf
*/
int	get_info(t_disp *disp, char *fname)
{
	int		fd;
	char	buf[FILE_DATA];
	char	**line_buf;
	int		end;
	int		beg;
	int		err_num;

	fd = open_file(fname);
	err_num = 0;
	if (read(fd, buf, FILE_DATA) < 0)
	{
		perror("The following error occurred");
		return (errno);
	}
	line_buf = ft_split(buf, '\n', &end);
	err_num = parse_config(disp, line_buf, &beg);
	if (err_num != 0)
		printf("Parsed Configurations Successfully!\n");
	disp->map.height = end - beg - 1;
	printf("Parsing map Start\n");
	if (err_num == 0)
		 err_num = get_map_data(disp, line_buf, beg);
	if (err_num != 0)
		printf("Parsing map Failed..!!\n");
	free(line_buf);

	return (err_num);
}

// *** gnl, ft_split free !!!!!!!!!!!!!
int main(int argc, char *argv[])
{
	t_disp	disp;
	int		err_num;

	if (argc == 2)
	{
		if (check_file(argv[1]))
			return (ERR_FILE);	
		if ((err_num = get_info(&disp, argv[1])) < 0)
		{
			printf("ERROR_NUMBER: %d\n", err_num);
			return (ERR_FILE);
		}
		show_map_data(disp);
#if 0
		if (cub3d_run(&disp))
			return (ERR_RUN);
#endif
	}
	return (0);
}
