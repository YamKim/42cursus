# include "cub3d.h"

extern int world_map[MAP_WIDTH][MAP_HEIGHT];

int main_loop(t_loop *lv)
{
	t_hit	hit_point;
    int		t;
	double	camera_t;
	double	*perp_buf;

	if (!(perp_buf = (double *)malloc(sizeof(double) * lv->disp->width)))
		return (ERR_MALLOC);
    t = 0;
    while (t < lv->disp->width)
    {
		hit_point.pos.x = (int)(lv->player->pos.x);
		hit_point.pos.y = (int)(lv->player->pos.y);
        camera_t = (2 * t / (double)(lv->disp->width)) - 1;
        lv->player->ray_dir.x = lv->player->dir.x + lv->player->plane.x * camera_t;
        lv->player->ray_dir.y = lv->player->dir.y + lv->player->plane.y * camera_t;
		hit_point.perp_wall_dist = dda_algorithm(lv->player, &hit_point);
		perp_buf[t] = hit_point.perp_wall_dist;
		draw_tex_wall(*(lv->disp), *(lv->player), t, hit_point);
		//draw_untex_wall(*(lv->disp), t, hit_point);
        ++t;
    } 
	draw_sprite(*lv->disp, *lv->player, hit_point, perp_buf);
	mlx_put_image_to_window(lv->disp->mlx_ptr, lv->disp->win_ptr, lv->disp->img.ptr, 0, 0);
	free(perp_buf);
	return (1);
}

void	set_player_info(t_player *player, char orient)
{
	player->pos.x = 12;
	player->pos.y = 5;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
	player->trans_speed = 0.1;
	player->rot_speed = ROT_SPEED;
	start_orient(player, orient);
}

int	cub3d_run(t_disp *disp)
{
	t_player	player;
	t_loop		loop_var;
	
	disp->mlx_ptr = mlx_init();
	set_player_info(&player, WEST);	
	disp->win_ptr = mlx_new_window(disp->mlx_ptr, disp->width, disp->height, "mlx");
	disp->img.ptr = mlx_new_image(disp->mlx_ptr, disp->width, disp->height);
	disp->img.data = (int *)mlx_get_data_addr(disp->img.ptr, &(disp->img.bpp),
					&(disp->img.size_l), &(disp->img.endian));
	// texture part
	//load_tex_group(disp);
	loop_var.disp = disp;
	loop_var.player = &player;
	mlx_loop_hook(disp->mlx_ptr, &main_loop, &loop_var);
	mlx_hook(disp->win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &player);
	mlx_loop(disp->mlx_ptr);

	return (0);
} 


int	check_file(char *fname)
{
	char	*ext;
	size_t	fname_len;
	int		fd;

	fname_len = ft_strlen(fname);
	ext = ft_substr(fname, fname_len - 4, fname_len);
	if (ft_strncmp(ext, FILE_EXTENSION, 4))
		return (ERR_FILE);
	return (0);
}

int	open_file(char *fname)
{
	int	ret;

	if ((ret = open(fname, O_RDONLY)) < 0)
	{
		perror("The following error occurred");
		return (errno);
	}
	return (ret);
}

// over max resolution -> max resolution
int	get_info(t_disp *disp, char *fname)
{
	int		fd;
	char	buf[FILE_DATA];
	char	**line_buf;

	fd = open_file(fname);
	if (read(fd, buf, FILE_DATA) < 0)
	{
		perror("The following error occurred");
		return (errno);
	}
	line_buf = ft_split(buf, '\n');
	if (parse_config(disp, line_buf))
	{
		printf("Parsing configuration error\n");
		free_split_arr(line_buf);
		return (errno);
	}
	printf("Let's parsing map!!\n");
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
		if (cub3d_run(&disp))
			return (ERR_RUN);
	}
	return (0);
}
