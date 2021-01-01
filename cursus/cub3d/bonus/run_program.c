/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:28:00 by yekim             #+#    #+#             */
/*   Updated: 2021/01/01 13:21:24 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

int				run_program(t_disp *disp, t_player *player, int capture_flag)
{
	t_loop	loop_var;

	init_player_setting(disp, player);
	loop_var = set_loop_val(disp, player);
	if (capture_flag)
		return (save_bmp_image(&loop_var));
	if (repeat_bgm(loop_var.player))
		return (ERR_PLAY_MUSIC);
	mlx_loop_hook(disp->mlx_ptr, &run_raycasting, &loop_var);
	mlx_hook(disp->win_ptr, EVENT_KEY_PRESS, 0, &key_press, &loop_var);
	mlx_hook(disp->win_ptr, EVENT_KEY_RELEASE, 0, &key_release, &loop_var);
	mlx_hook(disp->win_ptr, EVENT_MOUSE_PRESS, 0, &mouse_press, &loop_var);
	mlx_hook(disp->win_ptr, EVENT_MOUSE_RELEASE, 0, &mouse_release, &loop_var);
	mlx_hook(disp->win_ptr, EVENT_MOUSE_MOVE, 0, &mouse_move, &loop_var);
	mlx_hook(disp->win_ptr, EVENT_KEY_EXIT, 0, &finish_program, &loop_var);
	mlx_loop(disp->mlx_ptr);
	return (0);
}
