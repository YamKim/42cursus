/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:28:00 by yekim             #+#    #+#             */
/*   Updated: 2020/12/22 18:55:47 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_img_data(t_disp *disp, t_player *player, double *perp_buf, int secret)
{
	t_hit	hp;
	int		t;
	double	camera_t;

	t = -1;
	hp.secret_door = secret;
	while (++t < disp->w)
	{
		hp.pos.x = (int)(player->pos.x);
		hp.pos.y = (int)(player->pos.y);
		camera_t = (2 * t / (double)(disp->w)) - 1;
		player->ray_dir.x = player->dir.x + player->plane.x * camera_t;
		player->ray_dir.y = player->dir.y + player->plane.y * camera_t;
		hp.perp_wall_dist = dda_algorithm(player, &hp, disp->map);
		draw_tex_wall(disp, player, t, &hp);
		perp_buf[t] = hp.perp_wall_dist;
	}
	draw_sprite(disp, player, perp_buf);
	mlx_put_image_to_window(disp->mlx_ptr, disp->win_ptr, disp->img.ptr, 0, 0);
	return (0);
}

int	bonus_loop(t_loop *lv)
{
	int		ret;

	ret = 0;
	if (draw_skybox(lv->disp, lv->player))
		ret |= ERR_DRAW_IMG;
	if (draw_hud_series(lv->disp, lv->player))
		ret |= ERR_DRAW_IMG;
	return (ret);
}

int	main_loop(t_loop *lv)
{
	double	*perp_buf;
	int		ret;

	ret = 0;
	if (!(perp_buf = (double *)malloc(sizeof(double) * lv->disp->w)))
		return (ERR_MALLOC);
	if (draw_tex_background(lv->disp, lv->player))
		ret |= ERR_DRAW_IMG;
	if (draw_img_data(lv->disp, lv->player, perp_buf, 0))
		ret |= ERR_DRAW_IMG;
	if (draw_img_data(lv->disp, lv->player, perp_buf, 1))
		ret |= ERR_DRAW_IMG;
	ret |= bonus_loop(lv);
	key_update(lv);
	free(perp_buf);
	if (lv->player->life == MIN_LIFE)
		finish_program(lv);
	return (ret);
}

int	cub3d_run(t_disp *disp, t_player *player, int capture_flag)
{
	t_loop	loop_var;

	disp->mlx_ptr = mlx_init();
	disp->win_ptr = mlx_new_window(disp->mlx_ptr, disp->w, disp->h, "mlx");
	disp->img.ptr = mlx_new_image(disp->mlx_ptr, disp->w, disp->h);
	disp->img.data = (int *)mlx_get_data_addr(disp->img.ptr, &(disp->img.bpp),\
					&(disp->img.size_l), &(disp->img.endian));
	loop_var.disp = disp;
	loop_var.player = player;
#if 1
	if (capture_flag) {
		save_bmp_image(loop_var, disp);
	}
#endif
#if 0
	(void)capture_flag;
	mlx_loop_hook(disp->mlx_ptr, &main_loop, &loop_var);
	mlx_hook(disp->win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &loop_var);
	mlx_hook(disp->win_ptr, X_EVENT_KEY_RELEASE, 0, &key_release, &loop_var);
	mlx_loop(disp->mlx_ptr);
#endif
	return (0);
}
