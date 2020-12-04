#include "cub3d.h"

void	set_player_info(t_disp disp, t_player *player)
{
	player->pos = disp.start_pos;
	player->dir.x = 0;
	player->dir.y = 1;
	player->plane.x = 0.66;
	player->plane.y = 0;
	player->key = 0;
	player->trans_speed = TRANS_SPEED;
	player->rot_speed = ROT_SPEED;
	start_orient(player, disp.start_orient);
}

int	draw_img_data(t_disp *disp, t_player *player, double *perp_buf)
{
	t_hit	hit_point;
    int		t;
	double	camera_t;

    t = -1;
    while (++t < disp->w)
    {
		hit_point.pos.x = (int)(player->pos.x);
		hit_point.pos.y = (int)(player->pos.y);
        camera_t = (2 * t / (double)(disp->w)) - 1;
        player->ray_dir.x = player->dir.x + player->plane.x * camera_t;
        player->ray_dir.y = player->dir.y + player->plane.y * camera_t;
		hit_point.perp_wall_dist = dda_algorithm(player, &hit_point, disp->map);
		draw_tex_wall(*disp, *player, t, hit_point);
		//draw_untex_wall(*(disp), t, hit_point);
		perp_buf[t] = hit_point.perp_wall_dist;
    } 
	draw_sprite(*disp, player, hit_point, perp_buf);
	draw_item(disp, player, hit_point, perp_buf);
	mlx_put_image_to_window(disp->mlx_ptr, disp->win_ptr, disp->img.ptr, 0, 0);
	return (0);
}

int	set_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_skybox_color(t_map *map, t_veci idx, t_veci step)
{
	int	ret;

	ret = set_color(255, 0, 0, 0);
	if (map->data[idx.y / step.y][idx.x / step.x] == MAP_WALL_VAL)
		ret = set_color(100, 120, 120, 120);
	else if (map->data[idx.y / step.y][idx.x / step.x] == MAP_ROAD_VAL)
		ret = set_color(100, 200, 200, 200);
	else if (map->data[idx.y / step.y][idx.x / step.x] == MAP_ITEM_VAL)
		ret = set_color(100, 230, 30, 30);
	else if (map->data[idx.y / step.y][idx.x / step.x] == MAP_SECRET_VAL)
		ret = set_color(100, 218, 165, 32);
	return (ret);
}

int	draw_skybox(t_disp *disp, t_player player)
{
	t_img	skybox;
	t_veci	idx;
	t_veci	step;
	int		col;

	skybox.w = disp->w * DISP2SKY;
	skybox.h = disp->h * DISP2SKY;
	skybox.ptr = mlx_new_image(disp->mlx_ptr, skybox.w, skybox.h);
	skybox.data = (int *)mlx_get_data_addr(skybox.ptr, &(skybox.bpp),
				&(skybox.size_l), &(skybox.endian));
	step.x = skybox.w / disp->map.max_w;
	step.y = skybox.h / disp->map.h;
	for (int x = 0; x < skybox.w; ++x) {
		for (int y = 0; y < skybox.h; ++y) {
			idx.x = x;
			idx.y = y;
			skybox.data[(skybox.h - 1 - y) * skybox.w + x] = \
				get_skybox_color(&(disp->map), idx, step);
		}
	}
	mlx_put_image_to_window(disp->mlx_ptr, disp->win_ptr, skybox.ptr, 0, 0);
	return (0);
}

int main_loop(t_loop *lv)
{
	double	*perp_buf;

	if (!(perp_buf = (double *)malloc(sizeof(double) * lv->disp->w)))
		return (ERR_MALLOC);
	if (draw_tex_background(*lv->disp, *lv->player))
		return (ERR_DRAW_IMG);
	if (draw_img_data(lv->disp, lv->player, perp_buf))
		return (ERR_DRAW_IMG);
	if (draw_skybox(lv->disp, *lv->player))
		return (ERR_DRAW_IMG);
	key_update(lv);
	free(perp_buf);
	return (1);
}

int	cub3d_run(t_disp *disp)
{
	t_player	player;
	t_loop		loop_var;
	
	disp->mlx_ptr = mlx_init();
	set_player_info(*disp, &player);	
	disp->win_ptr = mlx_new_window(disp->mlx_ptr, disp->w, disp->h, "mlx");
	disp->img.ptr = mlx_new_image(disp->mlx_ptr, disp->w, disp->h);
	disp->img.data = (int *)mlx_get_data_addr(disp->img.ptr, &(disp->img.bpp),
					&(disp->img.size_l), &(disp->img.endian));
	// texture part
	loop_var.disp = disp;
	loop_var.player = &player;
	mlx_loop_hook(disp->mlx_ptr, &main_loop, &loop_var);
	mlx_hook(disp->win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &loop_var);
	mlx_hook(disp->win_ptr, X_EVENT_KEY_RELEASE, 0, &key_release, &loop_var);
	mlx_loop(disp->mlx_ptr);

	return (0);
} 
