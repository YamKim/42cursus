#include "cub3d.h"

extern int world_map[MAP_WIDTH][MAP_HEIGHT];

int		get_color(const t_hit map)
{
	int	ret;

	if (world_map[map.x][map.y] == 1)
	    ret = 0xFF0000;
	else if (world_map[map.x][map.y] == 2)
	    ret = 0x00FF00;
	else if (world_map[map.x][map.y] == 3)
	    ret = 0x0000FF;
	else if (world_map[map.x][map.y] == 4)
	    ret = 0xFFFFFF;
	else
	    ret = 0x123145;
    if (map.side == 1)
        ret /= 2;
	return (ret);
}

void	set_draw_untextured_wall(t_draw *draw, const t_hit hit_point)
{
	draw->line_height = (int)(SCREEN_HEIGHT / hit_point.perp_wall_dist);
	draw->beg = calc_max((SCREEN_HEIGHT / 2) - (draw->line_height / 2), 0);
	draw->end = calc_min((SCREEN_HEIGHT / 2) + (draw->line_height / 2), SCREEN_HEIGHT - 1);
	draw->y = 0;
}

/*==============================================================================
** @ function name: draw_line
** @ input parameter:
**			1. image data
**			2. index for screen width
**			3. information about hit to use perp_wall_dist and color
** @ output:
**			
** @ return :
** @ brief  : draw lines which is calculated by perp_wall_dist on screen.
** @ warning: 
**
===============================================================================*/
void	draw_untextured_line(int *data, const int x, const t_hit hit_point)
{
	t_draw	draw;

	set_draw_untextured_wall(&draw, hit_point);
	while (draw.y < draw.beg)
		data[(draw.y++) * SCREEN_WIDTH + x] = COLOR_CEIL;
	while (draw.y < draw.end)
		data[(draw.y++) * SCREEN_WIDTH + x] = get_color(hit_point);
	while (draw.y < SCREEN_HEIGHT)
		data[(draw.y++) * SCREEN_WIDTH + x] = COLOR_FLOOR;
}

/*==============================================================================
** @ function name: clear_draw
** @ input parameter:
**			1. image data
** @ output:
**			1. initialized image data
** @ return :
** @ brief  : clean buffer for image data to renew the screen
** @ warning: 
**
===============================================================================*/
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
