#include "cub3d.h"

extern int world_map[MAP_WIDTH][MAP_HEIGHT];

int		get_color(const t_hit hit_point)
{
	int	ret;

	if (world_map[hit_point.pos.x][hit_point.pos.y] == 1)
	    ret = 0xFF0000;
	else if (world_map[hit_point.pos.x][hit_point.pos.y] == 2)
	    ret = 0x00FF00;
	else if (world_map[hit_point.pos.x][hit_point.pos.y] == 3)
	    ret = 0x0000FF;
	else if (world_map[hit_point.pos.x][hit_point.pos.y] == 4)
	    ret = 0xFFFFFF;
	else
	    ret = 0x123145;
    if (hit_point.side == 1)
        ret /= 2;
	return (ret);
}

void	set_draw_untex_wall(t_disp disp, t_draw *draw, t_hit hit_point)
{
	if (fabs(hit_point.perp_wall_dist - 0.0) < EPSILON)
		draw->line_height = (int)(disp.height * 2);
	else
		draw->line_height = (int)(disp.height / hit_point.perp_wall_dist);
	draw->beg = (int)fmax((((double)disp.height - draw->line_height) / 2), 0);
	draw->end = (int)fmin((((double)disp.height + draw->line_height) / 2), disp.height - 1);
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
void	draw_untex_wall(t_disp disp, const int x, const t_hit hit_point)
{
	t_draw	draw;

	set_draw_untex_wall(disp, &draw, hit_point);
	while (draw.y < draw.beg)
		disp.img.data[(draw.y++) * disp.width + x] = disp.ceil_color;
	draw.y = draw.beg;
	while (draw.y < draw.end)
		disp.img.data[(draw.y++) * disp.width + x] = get_color(hit_point);
	while (draw.y < disp.height)
		disp.img.data[(draw.y++) * disp.width + x] = disp.floor_color;
}
#if 0
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
#endif
