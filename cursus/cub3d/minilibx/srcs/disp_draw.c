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
void	draw_line(int *data, const int x, const t_hit hit_point)
{
	int	line_height;
	int	draw_beg;
	int	draw_end;
	int	y;

	line_height = (int)(SCREEN_HEIGHT / hit_point.perp_wall_dist);
	draw_beg = calc_max((SCREEN_HEIGHT / 2) - (line_height / 2), 0);
	draw_end = calc_min((SCREEN_HEIGHT / 2) + (line_height / 2), SCREEN_HEIGHT - 1);
	y = 0;
	while (y < draw_beg)
		data[(y++) * SCREEN_WIDTH + x] = COLOR_CEIL;
	while (y < draw_end)
		data[(y++) * SCREEN_WIDTH + x] = get_color(hit_point);
	while (y < SCREEN_HEIGHT)
		data[(y++) * SCREEN_WIDTH + x] = COLOR_FLOOR;
}

void	draw_texture_line(
		int *data,
		t_texture texture,
		const int x,
		const int texture_x,
		const t_hit hit_point)
{
	int	line_height;
	int	draw_beg;
	int	draw_end;
	int	y;
	int	texture_y;
	double texture_pos;
	double step;

	line_height = (int)(SCREEN_HEIGHT / hit_point.perp_wall_dist);
	draw_beg = calc_max((SCREEN_HEIGHT / 2) - (line_height / 2), 0);
	draw_end = calc_min((SCREEN_HEIGHT / 2) + (line_height / 2), SCREEN_HEIGHT - 1);
    step = 1.0 * texture.height / line_height;
	texture_pos = ((double)draw_beg - (double)SCREEN_HEIGHT / 2 + (double)line_height / 2) * step;
	y = 0;
	texture_y = 0;
	while (y < draw_beg)
		data[(y++) * SCREEN_WIDTH + x] = COLOR_CEIL;
	while (y < draw_beg + line_height)
	{
	    texture_y = (int)texture_pos & (texture.height - 1);
	    texture_pos += step;
		texture_y += step;
	    int color = texture.data[texture_y * texture.width + texture_x];
	    if (hit_point.side == 1)
	        color = (color >> 1) & 8355711;
	    data[(y++) * SCREEN_WIDTH + x] = color;
	}
	while (y < SCREEN_HEIGHT)
		data[(y++) * SCREEN_WIDTH + x] = COLOR_FLOOR;
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
