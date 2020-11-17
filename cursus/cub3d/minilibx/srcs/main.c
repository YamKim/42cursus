# include "cub3d.h"

extern int	world_map[MAP_WIDTH][MAP_HEIGHT];

void verLine (t_info *info, int x, int y1, int y2, int color)
{
    int temp;

    temp = y1;
    while (temp <= y2)
    {
        mlx_pixel_put(info->mlx, info->win, x, temp, color);
        temp++;
    }
}

int key_press(int key, t_info *info)
{
    if (key == KEY_W)
		move_forward(info);

    if (key == KEY_S)
		move_backward(info);

    if (key == KEY_A)
		turn_left(info);

    if (key == KEY_D)
		turn_right(info);
    if (key == KEY_ESC)
        exit(0);
    return (0);
}

int main_loop(t_info *info)
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
        ray_dir.x = info->dir.x + info->plane.x * camera_t;
        ray_dir.y = info->dir.y + info->plane.y * camera_t;

        map.x = (int)(info->pos.x);
        map.y = (int)(info->pos.y);


        delta_dist.x = fabs(1 / ray_dir.x);
        delta_dist.y = fabs(1 / ray_dir.y);


        hit = 0;
        if (ray_dir.x < 0)
        {
            step.x = -1;
            side_dist.x = (info->pos.x - map.x) * delta_dist.x;
        }
        else
        {
            step.x = 1;
            side_dist.x = (map.x + 1.0 - info->pos.x) * delta_dist.x;
        }
        if (ray_dir.y < 0)
        {
            step.y = -1;
            side_dist.y = (info->pos.y - map.y) * delta_dist.y;
        }
        else
        {
            step.y = 1;
            side_dist.y = (map.y + 1.0 - info->pos.y) * delta_dist.y;
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
            perpWallDist = (map.x - info->pos.x + (1 - step.x) / 2) / ray_dir.x;
        else
            perpWallDist = (map.y - info->pos.y + (1 - step.y) / 2) / ray_dir.y;

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
        verLine(info, t, drawStart, drawEnd, color);
        t++;
    } 
	return (1);
}

int main()
{
    t_info info;
    info.mlx = mlx_init();

    info.pos.x = 12;
    info.pos.y = 5;
    info.dir.x = -1;
    info.dir.y = 0;
    info.plane.x = 0;
    info.plane.y = 0.66;
    info.trans_speed = 0.05;
    info.rot_speed = 0.05;

    info.win = mlx_new_window(info.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx");

    mlx_loop_hook(info.mlx, &main_loop, &info);
    mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);

    mlx_loop(info.mlx);
}
