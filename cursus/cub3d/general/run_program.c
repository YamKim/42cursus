/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:28:00 by yekim             #+#    #+#             */
/*   Updated: 2020/12/31 18:08:24 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	mlx_loop(disp->mlx_ptr);
	return (0);
}
