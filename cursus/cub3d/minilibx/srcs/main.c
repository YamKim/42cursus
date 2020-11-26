# include "cub3d.h"

extern int world_map[MAP_WIDTH][MAP_HEIGHT];

int main_loop(t_loop *lv)
{
	t_hit	hit_point;
    int		t;
	double	camera_t;
	double	z_buf[SCREEN_WIDTH];

    t = 0;
    while (t < SCREEN_WIDTH)
    {
		hit_point.pos.x = (int)(lv->player->pos.x);
		hit_point.pos.y = (int)(lv->player->pos.y);
        camera_t = (2 * t / (double)(SCREEN_WIDTH)) - 1;
        lv->player->ray_dir.x = lv->player->dir.x + lv->player->plane.x * camera_t;
        lv->player->ray_dir.y = lv->player->dir.y + lv->player->plane.y * camera_t;
		hit_point.perp_wall_dist = dda_algorithm(lv->player, &hit_point);
		z_buf[t] = hit_point.perp_wall_dist;
		draw_tex_wall(*(lv->disp), *(lv->player), t, hit_point);
		//draw_untex_wall(lv->disp->img.data, t, hit_point);
        ++t;
    } 
	draw_sprite(*lv->disp, *lv->player, t, hit_point, z_buf);
	mlx_put_image_to_window(lv->disp->mlx_ptr, lv->disp->win_ptr, lv->disp->img.ptr, 0, 0);
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

int	cub3d_run(void)
{
	t_player	player;
	t_disp		disp;
	t_loop		loop_var;

	disp.mlx_ptr = mlx_init();
	set_player_info(&player, WEST);	
	disp.win_ptr = mlx_new_window(disp.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx");
	disp.img.ptr = mlx_new_image(disp.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	disp.img.data = (int *)mlx_get_data_addr(disp.img.ptr, &(disp.img.bpp),
					&(disp.img.size_l), &(disp.img.endian));
	// texture part
	load_tex_group(&disp);
	loop_var.disp = &disp;
	loop_var.player = &player;
	mlx_loop_hook(disp.mlx_ptr, &main_loop, &loop_var);
	mlx_hook(disp.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &player);
	mlx_loop(disp.mlx_ptr);

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
		return (ERR_FILE);
	}
	return (ret);
}

void	parse_resolution(char **wrord_buf)
{

}

int	get_info(char *fname)
{
	int		fd;
	char	buf[FILE_DATA];
	ssize_t	read_size;
	char	**line_buf;
	char	**word_buf;
	int		k;

	fd = open_file(fname);
	if ((read_size = read(fd, buf, FILE_DATA)) < 0)
	{
		perror("The following error occurred");
		return (ERR_READ);
	}

	line_buf = ft_split(buf, '\n');
	k = 0;
	while (line_buf[k])
	{
		printf("line_buf[%d]: %s\n", k, line_buf[k]);
		word_buf = ft_split(line_buf[k], ' ');
		for (int i = 0; word_buf[i]; ++i)
			printf("word_buf[%d]: %s\n", i, word_buf[i]);
		
		free_split_arr(word_buf);
		++k;
	}
	
	free_split_arr(line_buf);
	
	return (0);
}

// *** gnl, ft_split free !!!!!!!!!!!!!
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (check_file(argv[1]))
			return (ERR_FILE);	
		if (get_info(argv[1]))
			return (ERR_FILE);
		if (cub3d_run())
			return (ERR_RUN);
	}
	return (0);
}
