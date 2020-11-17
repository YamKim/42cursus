# include "../mlx.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

// WASD
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

// KEYBOARD ESC
# define KEY_ESC 53

#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// EVENT KEY
#define X_EVENT_KEY_PRESS   2
#define X_EVENT_KEY_EXIT    17

typedef struct		s_vecd
{
	double	x;
	double	y;
}					t_vecd;

typedef struct		s_veci
{
	int	x;
	int	y;
}					t_veci;

typedef struct    s_info
{
	t_vecd	pos;
	t_vecd	dir;
	t_vecd	plane;
    void    *mlx;
    void    *win;
    double    trans_speed;
    double    rot_speed;
}                t_info;


int worldMap[MAP_WIDTH][MAP_HEIGHT] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

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
            if (worldMap[map.x][map.y] > 0)
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
        if (worldMap[map.x][map.y] == 1)
            color = 0xFF0000;
        else if (worldMap[map.x][map.y] == 2)
            color = 0x00FF00;
        else if (worldMap[map.x][map.y] == 3)
            color = 0x0000FF;
        else if (worldMap[map.x][map.y] == 4)
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

void	move_forward(t_info *info)
{
	t_vecd	after_move;

	after_move.x = info->pos.x + info->dir.x * info->trans_speed;
	after_move.y = info->pos.y + info->dir.y * info->trans_speed;
    if (!worldMap[(int)after_move.x][(int)(info->pos.y)])
        info->pos.x = after_move.x;
    if (!worldMap[(int)(info->pos.x)][(int)after_move.y])
        info->pos.y = after_move.y;
}

void	move_backward(t_info *info)
{
	t_vecd	after_move;

	after_move.x = info->pos.x - info->dir.x * info->trans_speed;
	after_move.y = info->pos.y - info->dir.y * info->trans_speed;
    if (!worldMap[(int)after_move.x][(int)(info->pos.y)])
		info->pos.x = after_move.x;
    if (!worldMap[(int)(info->pos.x)][(int)after_move.y])
		info->pos.y = after_move.y;
}

t_vecd	rotate_vec(t_vecd dir, double theta)
{
	t_vecd	ret;

	ret.x = dir.x * cos(theta) - dir.y * sin(theta);
	ret.y = dir.y * sin(theta) + dir.y * cos(theta);
	return (ret);
}

void	turn_left(t_info *info)
{
	info->dir = rotate_vec(info->dir, info->rot_speed);	
	info->plane = rotate_vec(info->plane, info->rot_speed);
}

void	turn_right(t_info *info)
{
	info->dir = rotate_vec(info->dir, -info->rot_speed);	
	info->plane = rotate_vec(info->plane, -info->rot_speed);
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
