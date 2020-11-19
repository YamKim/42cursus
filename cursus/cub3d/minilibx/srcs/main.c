# include "cub3d.h"

extern int	world_map[MAP_WIDTH][MAP_HEIGHT];

void verLine (int *data, int x, int h_start, int h, int color) {
	int	y;

	y = 0;
	while (y < h)
	{
		data[(y + h_start) * SCREEN_WIDTH + x] = color;
		++y;
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

#if 0
int main_loop(t_loop *loop_var)
{
	t_disp		*disp;
	t_player	*player;

	disp = loop_var->disp;
	player = loop_var->player;

    int		t;
	double	camera_t;
	t_vecd	ray_dir;

    double	perpWallDist;

    t = 0;
    while (t < SCREEN_WIDTH)
    {
		player->map.x = (int)(player->pos.x);
		player->map.y = (int)(player->pos.y);
        camera_t = (2 * t / (double)(SCREEN_WIDTH)) - 1;
        ray_dir.x = player->dir.x + player->plane.x * camera_t;
        ray_dir.y = player->dir.y + player->plane.y * camera_t;

        perpWallDist = dda_algorithm(player, ray_dir);

        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);
        int drawStart = (-lineHeight / 2) + (SCREEN_HEIGHT / 2);
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = (lineHeight / 2) + (SCREEN_HEIGHT / 2);
        if (drawEnd >= SCREEN_HEIGHT)
            drawEnd = SCREEN_HEIGHT - 1;

        int color = 0xFF0000;
#if 1
        if (world_map[player->map.x][player->map.y] == 1)
            color = 0xFF0000;
        else if (world_map[player->map.x][player->map.y] == 2)
            color = 0x00FF00;
        else if (world_map[player->map.x][player->map.y] == 3)
            color = 0x0000FF;
        else if (world_map[player->map.x][player->map.y] == 4)
            color = 0xFFFFFF;
        else
            color = 0x123145;
        //if (side == 1)
         //  color = color / 2;
#endif

        //verLine(player, t, drawStart, drawEnd, color);
		printf("DEBUG===================================\n");
		verLine(disp->img, t, drawStart, drawEnd - drawStart, color);
        ++t;
    } 
	mlx_put_image_to_window(disp->mlx_ptr, disp->win_ptr, disp->img->img_ptr, 0, 0);
	return (1);
}
#endif

#if 1
int main_loop(t_loop *loop_var)
{
	t_disp		*disp;
	t_player	*player;

	disp = loop_var->disp;
	player = loop_var->player;

    int		t;
	double	camera_t;
	t_vecd	ray_dir;
	t_veci	map;

	t_vecd	side_dist;
	t_vecd	delta_dist;
	t_veci	step;
	int		hit;
	int		side;
    double	perpWallDist;


    t = 0;
    while (t < SCREEN_WIDTH)
    {
        camera_t = (2 * t / (double)(SCREEN_WIDTH)) - 1;
        ray_dir.x = player->dir.x + player->plane.x * camera_t;
        ray_dir.y = player->dir.y + player->plane.y * camera_t;

        map.x = (int)(player->pos.x);
        map.y = (int)(player->pos.y);

        delta_dist.x = fabs(1 / ray_dir.x);
        delta_dist.y = fabs(1 / ray_dir.y);

        hit = 0;
        if (ray_dir.x < 0)
        {
            step.x = -1;
            side_dist.x = (player->pos.x - map.x) * delta_dist.x;
        }
        else
        {
            step.x = 1;
            side_dist.x = (map.x + 1.0 - player->pos.x) * delta_dist.x;
        }
        if (ray_dir.y < 0)
        {
            step.y = -1;
            side_dist.y = (player->pos.y - map.y) * delta_dist.y;
        }
        else
        {
            step.y = 1;
            side_dist.y = (map.y + 1.0 - player->pos.y) * delta_dist.y;
        }

        while (hit == 0)
        {
            if (side_dist.x < side_dist.y)
            {
                side_dist.x += delta_dist.x;
                map.x += step.x;
                side = 0;
            }
            else
            {
                side_dist.y += delta_dist.y;
                map.y += step.y;
                side = 1;
            }
            if (world_map[map.x][map.y] > 0)
                hit = 1;
        }

        if (side == 0)
            perpWallDist = (map.x - player->pos.x + (double)(1 - step.x) / 2) / ray_dir.x;
        else
            perpWallDist = (map.y - player->pos.y + (double)(1 - step.y) / 2) / ray_dir.y;

        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);
        int drawStart = (-lineHeight / 2) + (SCREEN_HEIGHT / 2);
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = (lineHeight / 2) + (SCREEN_HEIGHT / 2);
        if (drawEnd >= SCREEN_HEIGHT)
            drawEnd = SCREEN_HEIGHT - 1;

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

        if (side == 1)
            color = color / 2;
        //verLine(player, t, drawStart, drawEnd, color);
		verLine(disp->img.data, t, drawStart, drawEnd - drawStart, color);
        ++t;
    } 
	mlx_put_image_to_window(disp->mlx_ptr, disp->win_ptr, disp->img.img_ptr, 0, 0);
	return (1);
}
#endif

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
    player.trans_speed = 0.05;
    player.rot_speed = 0.05;

	disp.win_ptr = mlx_new_window(disp.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx");
	disp.img.img_ptr = mlx_new_image(disp.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	disp.img.data = (int *)mlx_get_data_addr(disp.img.img_ptr, &(disp.img.bpp), &(disp.img.size_l), &(disp.img.edian));
	loop_var.disp = &disp;
	loop_var.player = &player;
    mlx_loop_hook(disp.mlx_ptr, &main_loop, &loop_var);
    mlx_hook(disp.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &player);
    mlx_loop(disp.mlx_ptr);
}
