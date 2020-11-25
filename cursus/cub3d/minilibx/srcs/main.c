# include "cub3d.h"

extern int world_map[MAP_WIDTH][MAP_HEIGHT];

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


t_vecd test_pos = {0.0, 0.0};

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

	draw->line_height = (int)fabs(SCREEN_HEIGHT / spr_ray_dist.y);	
	draw->beg = calc_max((SCREEN_HEIGHT - draw->line_height) / 2, 0);
	draw->end = calc_min((SCREEN_HEIGHT + draw->line_height) / 2, SCREEN_HEIGHT - 1);

	//spr_width = (int)fabs(SCREEN_HEIGHT / spr_ray_dist.y);
	spr_width = draw->line_height;
	draw->xbeg = calc_max(spr_x_ctr - spr_width / 2 , 0);
	draw->xend = calc_min(spr_x_ctr + spr_width / 2 , SCREEN_WIDTH - 1);
	
	draw->y = draw->beg;
	draw->x = draw->xbeg;

}

void	draw_sprite_part(int *data, t_tex tex, t_player player, t_draw draw, int spr_x_ctr, double *z_buf)
{
	int	spr_width;

	spr_width = draw.line_height;
	while (draw.x < draw.xend)
	{
		draw.tx = (int)((256 * (draw.x - (spr_x_ctr - spr_width / 2)) * tex.width / spr_width) / 256);
		if(player.sray_dist.y > 0 && draw.x > 0 && draw.x < SCREEN_WIDTH && player.sray_dist.y < z_buf[draw.x])
		{
			for(draw.y = draw.beg; draw.y < draw.end; ++draw.y)
			{
				int d = draw.y * 256 - SCREEN_HEIGHT * 128 + draw.line_height * 128;
				draw.ty = ((d * tex.height) / draw.line_height) / 256;
				int color = tex.data[draw.ty * tex.width + draw.tx];
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

int main_loop(t_loop *lv)
{
	t_hit	hit_point;
    int		t;
	double	camera_t;
	double	z_buf[SCREEN_WIDTH];

    t = 0;
    while (t < SCREEN_WIDTH)
    {
		hit_point.pos.x = (int)(lv->player->pos.x);
		hit_point.pos.y = (int)(lv->player->pos.y);
        camera_t = (2 * t / (double)(SCREEN_WIDTH)) - 1;
        lv->player->ray_dir.x = lv->player->dir.x + lv->player->plane.x * camera_t;
        lv->player->ray_dir.y = lv->player->dir.y + lv->player->plane.y * camera_t;
		hit_point.perp_wall_dist = dda_algorithm(lv->player, &hit_point);
		z_buf[t] = hit_point.perp_wall_dist;
		draw_tex_wall(*(lv->disp), *(lv->player), t, hit_point);
		//draw_untex_line(lv->disp->img.data, t, hit_point);
        ++t;
    } 
	draw_sprite(*lv->disp, *lv->player, t, hit_point, z_buf);
	mlx_put_image_to_window(lv->disp->mlx_ptr, lv->disp->win_ptr, lv->disp->img.ptr, 0, 0);
	//clear_draw(lv->disp->img.data);
	return (1);
}

void	set_player_info(t_player *player)
{
	player->pos.x = 12;
	player->pos.y = 5;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
	player->trans_speed = 0.1;
	player->rot_speed = 0.05;
}

int main()
{
	t_player	player;
	t_disp		disp;
	t_loop		loop_var;
	
	disp.mlx_ptr = mlx_init();
	set_player_info(&player);	
	disp.win_ptr = mlx_new_window(disp.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx");
	disp.img.ptr = mlx_new_image(disp.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	disp.img.data = (int *)mlx_get_data_addr(disp.img.ptr, &(disp.img.bpp),
					&(disp.img.size_l), &(disp.img.endian));
	// texture part
	load_tex_group(&disp);
	loop_var.disp = &disp;
	loop_var.player = &player;
	mlx_loop_hook(disp.mlx_ptr, &main_loop, &loop_var);
	mlx_hook(disp.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &player);
	mlx_loop(disp.mlx_ptr);
}
