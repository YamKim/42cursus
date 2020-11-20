# include "cub3d.h"

extern int world_map[MAP_WIDTH][MAP_HEIGHT];
int		get_color(t_veci map)
{
	int color;

	if (world_map[map.x][map.y] == 1)
	    color = 0xFF0000;
	else if (world_map[map.x][map.y] == 2)
	    color = 0x00FF00;
	else if (world_map[map.x][map.y] == 3)
	    color = 0x0000FF;
	else if (world_map[map.x][map.y] == 4)
	    color = 0xFFFFFF;
	else
	    color = 0x123145;
	return (color);
}

void	draw_line(int *data, int x, double perp_wall_dist, int color)
{
	int	line_height;
	int	draw_beg;
	int	draw_end;
	int	y;

	line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
	draw_beg = calc_max((SCREEN_HEIGHT / 2) - (line_height / 2), 0);
	draw_end = calc_min((SCREEN_HEIGHT / 2) + (line_height / 2), SCREEN_HEIGHT - 1);

	y = 0;
	while (y < line_height)
	{
		data[(y + draw_beg) * SCREEN_WIDTH + x] = color;
		++y;
	}
}

void	clear_draw(int *data)
{
	int	y;
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			data[y * SCREEN_WIDTH + x] = 0;
			++y;
		}
		++x;
	}
}

int key_press(int key, t_player *player)
{
    if (key == KEY_W)
		move_forward(player);
    if (key == KEY_S)
		move_backward(player);
    if (key == KEY_A)
		turn_left(player);
    if (key == KEY_D)
		turn_right(player);
    if (key == KEY_ESC)
        exit(0);
    return (0);
}

int main_loop(t_loop *loop_var)
{
	t_disp		*disp;
	t_player	*player;
	t_veci		hit_point;

	disp = loop_var->disp;
	player = loop_var->player;

    int		t;
	double	camera_t;
	t_vecd	ray_dir;

    double	perp_wall_dist;

    t = 0;
    while (t < SCREEN_WIDTH)
    {
		hit_point.x = (int)(player->pos.x);
		hit_point.y = (int)(player->pos.y);
        camera_t = (2 * t / (double)(SCREEN_WIDTH)) - 1;
        ray_dir.x = player->dir.x + player->plane.x * camera_t;
        ray_dir.y = player->dir.y + player->plane.y * camera_t;

		int side = 0;
        perp_wall_dist = dda_algorithm(player, ray_dir, &hit_point, &side);

		int color;
		color = get_color(hit_point);
        if (side == 1)
           color = color / 2;
		draw_line(disp->img.data, t, perp_wall_dist, color);
        ++t;
    } 
	mlx_put_image_to_window(disp->mlx_ptr, disp->win_ptr, disp->img.img_ptr, 0, 0);
	clear_draw(disp->img.data);
	return (1);
}

int main()
{
	t_player	player;
	t_disp		disp;
	t_loop		loop_var;
	
	disp.mlx_ptr = mlx_init();
	
	player.pos.x = 12;
	player.pos.y = 5;
	player.dir.x = -1;
	player.dir.y = 0;
	player.plane.x = 0;
	player.plane.y = 0.66;
	player.trans_speed = 0.5;
	player.rot_speed = 0.1;
	
	disp.win_ptr = mlx_new_window(disp.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx");
	disp.img.img_ptr = mlx_new_image(disp.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	disp.img.data = (int *)mlx_get_data_addr(disp.img.img_ptr, &(disp.img.bpp),
					&(disp.img.size_l), &(disp.img.edian));
	loop_var.disp = &disp;
	loop_var.player = &player;
	mlx_loop_hook(disp.mlx_ptr, &main_loop, &loop_var);
	mlx_hook(disp.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &player);
	mlx_loop(disp.mlx_ptr);
}
