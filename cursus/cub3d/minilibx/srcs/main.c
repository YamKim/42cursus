# include "cub3d.h"

extern int	world_map[MAP_WIDTH][MAP_HEIGHT];

#if 0
void verLine (t_player *player, int x, int y1, int y2, int color)
{
    int temp;

    temp = y1;
    while (temp <= y2)
    {
        mlx_pixel_put(player->mlx_ptr, player->win_ptr, x, temp, color);
        temp++;
    }
}
#endif

void verLine (t_player *player, int x, int h_start, int h, int color) {
	int	y;

	y = 0;
	while (y < h)
	{
		(player->data)[(y + h_start) * SCREEN_WIDTH + x] = color;
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
	{
		//mlx_destroy_image(player->mlx, player->img_ptr);
        exit(0);
	}
    return (0);
}

int main_loop(t_player *player)
{
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
            perpWallDist = (map.x - player->pos.x + (1 - step.x) / 2) / ray_dir.x;
        else
            perpWallDist = (map.y - player->pos.y + (1 - step.y) / 2) / ray_dir.y;

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
		verLine(player, t, drawStart, drawEnd - drawStart, color);
        //verLine(player, t, drawStart, drawEnd, color);
        ++t;
    } 
	mlx_put_image_to_window(player->mlx_ptr, player->win_ptr, player->img_ptr, 0, 0);
	return (1);
}

int main()
{
    t_player	player;

	player.mlx_ptr = mlx_init();

    player.pos.x = 12;
    player.pos.y = 5;
    player.dir.x = -1;
    player.dir.y = 0;
    player.plane.x = 0;
    player.plane.y = 0.66;
    player.trans_speed = 0.05;
    player.rot_speed = 0.05;

    player.win_ptr = mlx_new_window(player.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx");
	player.img_ptr = mlx_new_image(player.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	player.data = (int *)mlx_get_data_addr(player.img_ptr, &player.bpp, &player.size_l, &player.edian);

#if 0
	int y = 0;
	while (y < 100)
	{
		player.data[y * SCREEN_WIDTH + 50] = 0x00FF0000;
		++y;
	}
	mlx_put_image_to_window(player.mlx_ptr, player.win_ptr, player.img_ptr, 0, 0);
#endif

    mlx_loop_hook(player.mlx_ptr, &main_loop, &player);
    mlx_hook(player.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &player);

    mlx_loop(player.mlx_ptr);
}
