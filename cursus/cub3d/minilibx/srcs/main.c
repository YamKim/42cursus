# include "cub3d.h"

extern int world_map[MAP_WIDTH][MAP_HEIGHT];

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

int main_loop(t_loop *lv)
{
	t_hit	hit_point;
    int		t;
	double	camera_t;

    t = 0;
    while (t < SCREEN_WIDTH)
    {
		hit_point.x = (int)(lv->player->pos.x);
		hit_point.y = (int)(lv->player->pos.y);
        camera_t = (2 * t / (double)(SCREEN_WIDTH)) - 1;
        lv->player->ray_dir.x = lv->player->dir.x + lv->player->plane.x * camera_t;
        lv->player->ray_dir.y = lv->player->dir.y + lv->player->plane.y * camera_t;
		hit_point.perp_wall_dist = dda_algorithm(lv->player, &hit_point);
		draw_texture_line(*lv->disp, *lv->player, t, hit_point);
		//draw_line(lv->disp->img.data, t, hit_point);
        ++t;
    } 
	mlx_put_image_to_window(lv->disp->mlx_ptr, lv->disp->win_ptr, lv->disp->img.ptr, 0, 0);
	clear_draw(lv->disp->img.data);
	return (1);
}

void	set_player_info(t_player *player)
{
	player->pos.x = 12;
	player->pos.y = 5;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
	player->trans_speed = 0.5;
	player->rot_speed = 0.1;
}

int main()
{
	t_player	player;
	t_disp		disp;
	t_loop		loop_var;
	
	disp.mlx_ptr = mlx_init();
	set_player_info(&player);	
	disp.win_ptr = mlx_new_window(disp.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx");
	disp.img.ptr = mlx_new_image(disp.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	disp.img.data = (int *)mlx_get_data_addr(disp.img.ptr, &(disp.img.bpp),
					&(disp.img.size_l), &(disp.img.endian));
	// texture part
	load_texture_group(&disp);
	check_texture(disp);
	loop_var.disp = &disp;
	loop_var.player = &player;
	mlx_loop_hook(disp.mlx_ptr, &main_loop, &loop_var);
	mlx_hook(disp.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &player);
	mlx_loop(disp.mlx_ptr);
}
