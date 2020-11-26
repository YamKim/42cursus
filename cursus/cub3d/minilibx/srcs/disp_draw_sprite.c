#include "cub3d.h"

t_spr	g_sprite[SPRITE_NUMBER] =
{
	{20.5, 11.5, 10},
	//green lights in every room
	{18.5, 4.5, 10},
	{10.0, 4.5, 10},
	{10.0, 12.5,10},
	{3.5, 6.5, 10},
	{3.5, 20.5, 10},
	{3.5, 14.5, 10},
	{14.5, 20.5, 10},

	//row of pillars in front of wall: fisheye test
	{18.5, 10.5, 9},
	{18.5, 11.5, 9},
	{18.5, 12.5, 9},

	//some barrels around the map
	{21.5, 1.5, 8},
	{15.5, 1.5, 8},
	{16.0, 1.8, 8},
	{16.2, 1.2, 8},
	{3.5, 2.5, 8},
	{9.5, 15.5, 8},
	{10.0, 15.1, 8},
	{10.5, 15.8, 8},
};

void	set_sprite(t_pair *spr_pair, t_player player)
{
	int	i;

	i = 0;
	while (i < SPRITE_NUMBER)
	{
		spr_pair[i].order = i;
		spr_pair[i].dist = calc_dist(player.pos, g_sprite[i].pos);
		++i;
	}	
}

t_vecd	get_spr_ray(t_player player, t_pair spr_pair)
{
	t_vecd	ret;
	double	det;
	t_vecd	spr_dist;

	spr_dist.x = g_sprite[spr_pair.order].pos.x - player.pos.x;
	spr_dist.y = g_sprite[spr_pair.order].pos.y - player.pos.y;
	det = calc_det(player.plane, player.dir);
	ret.x = (player.dir.y * spr_dist.x - player.dir.x * spr_dist.y) / det;
	ret.y = (-player.plane.y * spr_dist.x + player.plane.x * spr_dist.y) / det;
	return (ret);
}

void	sort_spr_pair(t_pair *spr_pair)
{
	int		i;
	int		j;
	double	remember;
	int		tmp_order;

	i = 1;
	while (i < SPRITE_NUMBER)
	{
		remember = spr_pair[i].dist;
		j = i;
		while (--j >= 0 && remember > spr_pair[j].dist)
		{
			spr_pair[j + 1].dist = spr_pair[j].dist;
			spr_pair[j].dist = remember;
			tmp_order = spr_pair[j].order;
			spr_pair[j].order = spr_pair[j + 1].order;
			spr_pair[j + 1].order = tmp_order;
		}
		++i;
	}
}

void	set_draw_sprite(t_draw *draw, int spr_x_ctr, t_vecd spr_ray_dist)
{
	int spr_width;

	draw->line_height = (int)fabs((double)SCREEN_HEIGHT / spr_ray_dist.y);	
	draw->beg = (int)fmax((double)(SCREEN_HEIGHT - draw->line_height) / 2, 0.0);
	draw->end = (int)fmin((double)(SCREEN_HEIGHT + draw->line_height) / 2, SCREEN_HEIGHT - 1);

	//spr_width = (int)fabs(SCREEN_HEIGHT / spr_ray_dist.y);
	spr_width = draw->line_height;
	draw->xbeg = (int)fmax((double)spr_x_ctr - (double)spr_width / 2 , 0.0);
	draw->xend = (int)fmin((double)spr_x_ctr + (double)spr_width / 2 , SCREEN_WIDTH - 1);
	
	draw->y = draw->beg;
	draw->x = draw->xbeg;

}

void	draw_sprite_part(int *data, t_tex tex, t_player player, t_draw draw, int spr_x_ctr, double *z_buf)
{
	int	spr_width;
	int	tmp;
	int	color;

	spr_width = draw.line_height;
	while (draw.x < draw.xend)
	{
		draw.tx = (int)((256 * (draw.x - (spr_x_ctr - spr_width / 2)) * tex.width / spr_width) / 256);
		if(player.sray_dist.y > 0 && draw.x > 0 && draw.x < SCREEN_WIDTH && player.sray_dist.y < z_buf[draw.x])
		{
			for(draw.y = draw.beg; draw.y < draw.end; ++draw.y)
			{
				tmp = draw.y * 256 - SCREEN_HEIGHT * 128 + draw.line_height * 128;
				draw.ty = ((tmp * tex.height) / draw.line_height) / 256;
				color = tex.data[draw.ty * tex.width + draw.tx];
				if((color & 0x00FFFFFF) != 0)
					data[draw.y * SCREEN_WIDTH + draw.x] = color;
			}
		}
		++draw.x;
	}
}

int		draw_sprite(t_disp disp, t_player player, int x, t_hit hit_point, double *z_buf)
{
	t_pair	spr_pair[SPRITE_NUMBER];
	t_draw	draw;
	int		spr_x_ctr;
	int		spr_width;

	set_sprite(spr_pair, player); 
	sort_spr_pair(spr_pair);
	int	i;
	i = 0;
	while (i < SPRITE_NUMBER)
	{
		player.sray_dist = get_spr_ray(player, spr_pair[i]);
		spr_x_ctr = (int)((double)SCREEN_WIDTH / 2 * (1 + player.sray_dist.x / player.sray_dist.y));
		set_draw_sprite(&draw, spr_x_ctr, player.sray_dist); 
		spr_width = draw.line_height;
		t_tex tex = disp.tex[g_sprite[spr_pair[i].order].tex_nbr];
		draw_sprite_part(disp.img.data, tex, player, draw, spr_x_ctr, z_buf);
		++i;
	}
	return (1);
}
