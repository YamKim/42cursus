/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 19:19:38 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 06:07:09 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	finish_program(t_loop *lv)
{
	lst_clear(&(lv->disp->spr_lst));
	system("killall afplay");
	if (lv->player->life == MIN_LIFE)
		printf("GAME OVER=========================================\n");
	lv->player->sound = system("afplay -v 0.30 ./sound/sound_endgame.mp3\
								&>/dev/null &");
	mlx_destroy_window(lv->disp->mlx_ptr, lv->disp->win_ptr);
	printf("PROGRAM FINISHED======================================\n");
	exit(0);
}