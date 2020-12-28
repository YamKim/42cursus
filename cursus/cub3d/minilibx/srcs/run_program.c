/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:28:00 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 06:07:20 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static int		draw_main(
				t_disp *disp,
				t_player *player,
				double *perp_buf,
				int secret)
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

static int		repeat_bgm(t_player *player)
{
	long	cps;
	clock_t	cur_time;

	cur_time = clock();
	cps = CLOCKS_PER_SEC;
	if ((double)(cur_time - player->sound) / cps >= 120)
	{
		system("afplay -v 0.30 ./sound/maintheme.mp3 &>/dev/null &");
		player->sound = cur_time;
	}
	return (0);
}

int				run_raycasting(t_loop *lv)
{
	double	*perp_buf;
	int		ret;

	ret = 0;
	if (!(perp_buf = (double *)malloc(sizeof(double) * lv->disp->w)))
		return (ERR_MALLOC);
	if (repeat_bgm(lv->player))
		return (ERR_PLAY_MUSIC);
	if (draw_background(lv->disp, lv->player))
		ret |= ERR_DRAW_IMG;
	if (draw_main(lv->disp, lv->player, perp_buf, 0))
		ret |= ERR_DRAW_IMG;
	if (draw_main(lv->disp, lv->player, perp_buf, 1))
		ret |= ERR_DRAW_IMG;
	if (draw_skybox(lv->disp, lv->player))
		ret |= ERR_DRAW_IMG;
	if (draw_hud_series(lv->disp, lv->player))
		ret |= ERR_DRAW_IMG;
	key_update(lv);
	free(perp_buf);
	if (lv->player->life == MIN_LIFE)
		finish_program(lv);
	return (ret);
}

int				run_program(t_disp *disp, t_player *player, int capture_flag)
{
	t_loop	loop_var;

	init_player_setting(disp, player);
	loop_var = set_loop_val(disp, player);
	if (capture_flag)
		return (save_bmp_image(&loop_var));
	mlx_loop_hook(disp->mlx_ptr, &run_raycasting, &loop_var);
	mlx_hook(disp->win_ptr, EVENT_KEY_PRESS, 0, &key_press, &loop_var);
	mlx_hook(disp->win_ptr, EVENT_KEY_RELEASE, 0, &key_release, &loop_var);
	mlx_hook(disp->win_ptr, EVENT_MOUSE_PRESS, 0, &mouse_press, &loop_var);
	mlx_hook(disp->win_ptr, EVENT_MOUSE_RELEASE, 0, &mouse_release, &loop_var);
	mlx_hook(disp->win_ptr, EVENT_MOUSE_MOVE, 0, &mouse_move, &loop_var);
	mlx_loop(disp->mlx_ptr);
	return (0);
}
