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
	mlx_put_image_to_window(disp->mlx_ptr, disp->win_ptr, disp->img.ptr, 0, 0);
	clear_draw(disp->img.data);
	return (1);
}

void	load_texture(t_texture *texture, char *file_name)
{
	t_disp	tmp_disp;
	int		tmp_val;

	tmp_disp.mlx_ptr = mlx_init();
	texture->ptr = mlx_xpm_file_to_image(tmp_disp.mlx_ptr, file_name,
											&(texture->width), &(texture->height));
	texture->data = (int *)mlx_get_data_addr(texture->ptr,
											&tmp_val, &tmp_val, &tmp_val);	
	mlx_destroy_image(tmp_disp.mlx_ptr, texture->ptr);
}

void	load_texture_group(t_disp *disp)
{
    load_texture(&(disp->texture[0]), "textures/eagle.xpm");
    load_texture(&(disp->texture[1]), "textures/redbrick.xpm");
    load_texture(&(disp->texture[2]), "textures/purplestone.xpm");
    load_texture(&(disp->texture[3]), "textures/greystone.xpm");
    load_texture(&(disp->texture[4]), "textures/bluestone.xpm");
    load_texture(&(disp->texture[5]), "textures/mossy.xpm");
    load_texture(&(disp->texture[6]), "textures/wood.xpm");
    load_texture(&(disp->texture[7]), "textures/colorstone.xpm");
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

	loop_var.disp = &disp;
	loop_var.player = &player;
	mlx_loop_hook(disp.mlx_ptr, &main_loop, &loop_var);
	mlx_hook(disp.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &player);
	mlx_loop(disp.mlx_ptr);
}
