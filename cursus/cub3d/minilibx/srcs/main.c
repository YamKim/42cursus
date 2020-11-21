# include "cub3d.h"

extern int world_map[MAP_WIDTH][MAP_HEIGHT];

int		draw_texture(
		t_disp disp,
		int *data,
		const t_player player,
		const t_vecd ray_dir,
		const int x,
		const t_hit hit_point)
{
	double	wall_t;
	t_texture	texture;
	int		texture_t;
	int		texture_num;

	texture_num = world_map[hit_point.x][hit_point.y] - 1;
	texture = disp.texture[texture_num];
	texture.width = disp.texture[texture_num].width;
	texture.height = disp.texture[texture_num].height;

	if (hit_point.side == 0)
		wall_t = player.pos.y + hit_point.perp_wall_dist * ray_dir.y;
	else
		wall_t = player.pos.x + hit_point.perp_wall_dist * ray_dir.x;
	wall_t -= floor(wall_t);
	
	texture_t = (int)(wall_t * (double)(texture.width));
	if(hit_point.side == 0 && ray_dir.x > 0)
		texture_t = texture.width - texture_t - 1;
	if(hit_point.side == 1 && ray_dir.y < 0)
		texture_t = texture.width - texture_t - 1;
	draw_texture_line(data, texture, x, texture_t, hit_point);
	return (1);	
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
	t_hit		hit_point;

	disp = loop_var->disp;
	player = loop_var->player;

    int		t;
	double	camera_t;
	t_vecd	ray_dir;

    t = 0;
    while (t < SCREEN_WIDTH)
    {
		hit_point.x = (int)(player->pos.x);
		hit_point.y = (int)(player->pos.y);
        camera_t = (2 * t / (double)(SCREEN_WIDTH)) - 1;
        ray_dir.x = player->dir.x + player->plane.x * camera_t;
        ray_dir.y = player->dir.y + player->plane.y * camera_t;
		hit_point.perp_wall_dist = dda_algorithm(player, ray_dir, &hit_point);
		draw_texture(*disp, disp->img.data, *player, ray_dir, t, hit_point);
		//draw_line(disp->img.data, t, hit_point);
        ++t;
    } 
	mlx_put_image_to_window(disp->mlx_ptr, disp->win_ptr, disp->img.ptr, 0, 0);
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
