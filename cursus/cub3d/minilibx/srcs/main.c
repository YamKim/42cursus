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
#if 0
	if (fabs(test_pos.x - player.pos.x) > EPSILON)
	{
		for (int i = 0; i < SPRITE_NUMBER; ++i)
		{
			printf("spr_pair.order: %d, spr_pair.dist: %lf\n", spr_pair[i].order, spr_pair[i].dist);
			printf("pos.x: %lf, pos.y: %lf\n", player.pos.x, player.pos.y);
			test_pos.x = player.pos.x;
			test_pos.y = player.pos.y;
		}
	}
#endif
}

t_vecd	get_spr_ray(t_player player, t_pair spr_pair)
{
	t_vecd	ret;
	double	det;
	t_vecd	spr_dist;

	// 단일 sprite에 대해서 수행
	spr_dist.x = g_sprite[spr_pair.order].pos.x - player.pos.x;
	spr_dist.y = g_sprite[spr_pair.order].pos.y - player.pos.y;
	det = calc_det(player.plane, player.dir);
	ret.x = (player.dir.y * spr_dist.x - player.dir.x * spr_dist.y) / det;
	ret.y = (-player.plane.y * spr_dist.x + player.plane.x * spr_dist.y) / det;
	return (ret);
}

int		draw_sprite(t_disp disp, t_player player, int x, t_hit hit_point, double *z_buf)
{
	t_pair	spr_pair[SPRITE_NUMBER];
	t_vecd	spr_ray_dist;
	int		spr_x_ctr;
	t_draw	draw;

	// 모든 sprite에 대한 세팅
	set_sprite(spr_pair, player); 
	// sort 알고리즘 수행
	
	// 단일 sprite에 대한 세팅
	int	i;
	i = 0;
	while (i < SPRITE_NUMBER)
	{
		spr_ray_dist = get_spr_ray(player, spr_pair[i]);
		spr_x_ctr = (int)((double)SCREEN_WIDTH / 2 + (1 + spr_ray_dist.x / spr_ray_dist.y));
		draw.line_height = (int)fabs(SCREEN_HEIGHT / spr_ray_dist.y);	
		draw.beg = calc_max((SCREEN_HEIGHT - draw.line_height) / 2, 0);
		draw.end = calc_min((SCREEN_HEIGHT + draw.line_height) / 2, SCREEN_HEIGHT - 1);

		int spr_width = (int)fabs(SCREEN_HEIGHT / spr_ray_dist.y);
		int spr_height = (int)fabs(SCREEN_HEIGHT / spr_ray_dist.y);
		int draw_xbeg = calc_max(spr_x_ctr - spr_width / 2 , 0);
		int draw_xend = calc_min(spr_x_ctr + spr_width / 2 , SCREEN_WIDTH - 1);

		t_tex tex = disp.tex[g_sprite[i].tex_nbr];

		for (int sprite = draw_xbeg; sprite < draw_xend; ++sprite) {
			int texX = (int)((256 * (sprite - (spr_x_ctr - spr_width / 2)) * tex.width / spr_width) / 256);
			if(spr_ray_dist.y > 0 && sprite > 0 && sprite < SCREEN_WIDTH && spr_ray_dist.y < z_buf[sprite])
			{
				for(int y = draw.beg; y < draw.end; ++y)
				{
					int d = y * 256 - SCREEN_HEIGHT * 128 + spr_height * 128;
					int texY = ((d * tex.height) / spr_height) / 256;
					int color = tex.data[tex.width * texY + texX];
					if((color & 0x00FFFFFF) != 0) disp.img.data[y * SCREEN_WIDTH + x] = color;
				}
			}
		}
	}
#if 0
	for (int i = 0; i < SPRITE_NUMBER; ++i) {
		printf("sprite-> x: %lf, y: %lf, tex: %d, order: %d, dist: %lf\n", g_sprite[i].x, g_sprite[i].y, g_sprite[i].tex_nbr, g_sprite[i].order, g_sprite[i].dist);
	}
#endif
			
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
		draw_sprite(*lv->disp, *lv->player, t, hit_point, z_buf);
		//draw_untex_line(lv->disp->img.data, t, hit_point);
        ++t;
    } 
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
