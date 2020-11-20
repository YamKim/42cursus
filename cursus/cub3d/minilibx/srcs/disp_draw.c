#include "cub3d.h"

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
	while (y < draw_beg)
		data[(y++) * SCREEN_WIDTH + x] = COLOR_CEIL;
	while (y < draw_beg + line_height)
		data[(y++) * SCREEN_WIDTH + x] = color;
	while (y < SCREEN_HEIGHT)
		data[(y++) * SCREEN_WIDTH + x] = COLOR_FLOOR;
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
			data[(y++) * SCREEN_WIDTH + (x++)] = 0;
	}
}
