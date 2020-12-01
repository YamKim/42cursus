#include "cub3d.h"

void	set_player_info(t_disp disp, t_player *player)
{
	player->pos.x = disp.start_pos.x;
	player->pos.y = disp.start_pos.y;
	player->dir.x = 0;
	player->dir.y = 1;
	player->plane.x = 0.66;
	player->plane.y = 0;
	player->key = 0;
	player->trans_speed = TRANS_SPEED;
	player->rot_speed = ROT_SPEED;
	start_orient(player, disp.start_orient);
}

int main_loop(t_loop *lv)
{
	t_hit	hit_point;
    int		t;
	double	camera_t;
	double	*perp_buf;

	if (!(perp_buf = (double *)malloc(sizeof(double) * lv->disp->width)))
		return (ERR_MALLOC);
	draw_tex_floor(*lv->disp, *lv->player);
    t = 0;
    while (t < lv->disp->width)
    {
		hit_point.pos.x = (int)(lv->player->pos.x);
		hit_point.pos.y = (int)(lv->player->pos.y);
        camera_t = (2 * t / (double)(lv->disp->width)) - 1;
        lv->player->ray_dir.x = lv->player->dir.x + lv->player->plane.x * camera_t;
        lv->player->ray_dir.y = lv->player->dir.y + lv->player->plane.y * camera_t;
		hit_point.perp_wall_dist = dda_algorithm(lv->player, &hit_point, lv->disp->map);
		perp_buf[t] = hit_point.perp_wall_dist;
		draw_tex_wall(*(lv->disp), *(lv->player), t, hit_point);
		//draw_untex_wall(*(lv->disp), t, hit_point);
        ++t;
    } 
	draw_sprite(*lv->disp, *lv->player, hit_point, perp_buf);
	mlx_put_image_to_window(lv->disp->mlx_ptr, lv->disp->win_ptr, lv->disp->img.ptr, 0, 0);
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
	disp->win_ptr = mlx_new_window(disp->mlx_ptr, disp->width, disp->height, "mlx");
	disp->img.ptr = mlx_new_image(disp->mlx_ptr, disp->width, disp->height);
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
