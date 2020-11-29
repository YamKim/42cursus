#include "cub3d.h"

int	get_map_height(char **line_buf)
{
	int	k;

	k = 0;
	while (line_buf[k])
		++k;
	return (k - 1);
}

int	get_pos_data(t_disp *disp, char data, int r, int c)
{
	if (data == MAP_ROAD)
		return (MAP_ROAD_VAL);
	else if (data == MAP_WALL)
		return (MAP_WALL_VAL);
	else if (data == MAP_SPRITE)
	{
		disp->spr_buf[disp->spr_cnt].pos.y = r + 0.5;
		disp->spr_buf[disp->spr_cnt].pos.x = c + 0.5;
		disp->spr_buf[disp->spr_cnt].tex_nbr = CONFIG_S;
		disp->spr_cnt += 1;
		return (MAP_SPRITE_VAL);
	}
	else if (data == NORTH || data == SOUTH || data == WEST || data == EAST)
	{
		if (disp->map.pos_flag)
			return (ERR_PARSE_MAP);
		disp->map.pos_flag = 1; 
		disp->start_pos.y = r + 0.5;
		disp->start_pos.x = c + 0.5;
		disp->start_orient = data;
		printf("start pos.y: %lf, pos.x: %lf\n", disp->start_pos.y, disp->start_pos.x);
		return (0);
	}
	return (ERR_PARSE_MAP);
}

#if 0
int	is_map_close(char **map, int map_height)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_height)
	{
		x = 0;
		while (map[y][x] != MAP_BOARDER_VAL)
		{
			if (map[y][x] == MAP_ROAD || map[y][x] == MAP_WALL)
			{
				if (map[y - 1][x] == 	
			}
			++x;
		}
		++y;
	}
	return (0);
}
#endif

int	get_map_data(t_disp *disp, char **map, int map_beg, int map_end)
{
	int	y;
	int r;
	int	x;

	disp->map.pos_flag = 0;
	disp->spr_cnt = 0;
	r = map_beg;
	y = map_end - map_beg;
	while (r <= map_end)
	{
		x = 0;
		while (map[r][x])
		{
			disp->map.data[y][x] = get_pos_data(disp, map[r][x], y, x);
			++x;
		}
		disp->map.data[y][x] = MAP_BOARDER_VAL;
		++r;
		--y;
	}
	if (disp->map.pos_flag != 1)
		return (ERR_PARSE_MAP);
#if 0
	if (is_map_close(map, map_end - map_beg + 1))
		return (ERR_PARSE_MAP);
#endif
#if 1
	for (int y = 0; y < map_end - map_beg + 1; ++y) {
		for (int x = 0; x < 20; ++x)
			printf("%d", disp->map.data[y][x]);
		printf("\n");

	}
#endif
	return (0);
}

// over max resolution -> max resolution
int	get_info(t_disp *disp, char *fname)
{
	int		fd;
	char	buf[FILE_DATA];
	char	**line_buf;
	int		line_num;
	int		map_height;
	int		map_beg;

	fd = open_file(fname);
	if (read(fd, buf, FILE_DATA) < 0)
	{
		perror("The following error occurred");
		return (errno);
	}
	line_buf = ft_split(buf, '\n', &line_num);
	if (parse_config(disp, line_buf, &map_beg) == ERR_PARSE_CONFIG)
	{
		printf("Parsing configuration error\n");
		free_split_arr(line_buf);
		return (errno);
	}
	// allocate memory space 
	map_height = get_map_height(line_buf);
	get_map_data(disp, line_buf, map_beg, map_height);
	
	// exclude last line.
	free_split_arr(line_buf);

	return (0);
}

// *** gnl, ft_split free !!!!!!!!!!!!!
int main(int argc, char *argv[])
{
	t_disp	disp;

	if (argc == 2)
	{
		if (check_file(argv[1]))
			return (ERR_FILE);	
		if (get_info(&disp, argv[1]))
			return (ERR_FILE);
#if 0
		if (cub3d_run(&disp))
			return (ERR_RUN);
#endif
	}
	return (0);
}
