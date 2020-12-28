/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:20:41 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 06:07:18 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	set_zaxis_motion(t_disp *disp, t_player *player)
{
	if (player->key & (1 << MOVE_H))
		disp->hctr_bias = PLAYER_UP;
	else if (player->key & (1 << MOVE_G))
		disp->hctr_bias = PLAYER_DOWN;
	else
		disp->hctr_bias = 0;
}

void	open_door_trigger(t_disp *disp, t_player *player)
{
	t_vecd	door_dir;
	int		map_type;

	door_dir.y = player->pos.y + player->dir.y;
	door_dir.x = player->pos.x + player->dir.x;
	map_type = disp->map.data[(int)door_dir.y][(int)door_dir.x];
	if (map_type == MAP_CLDOOR_VAL)
	{
		disp->map.data[(int)door_dir.y][(int)door_dir.x] = MAP_OPDOOR_VAL;
		printf("door is opened\n");
		system("afplay -v 0.30 ./sound/sound_break.mp3 &>/dev/null &");
	}
	if (map_type == MAP_OPDOOR_VAL)
	{
		disp->map.data[(int)door_dir.y][(int)door_dir.x] = MAP_CLDOOR_VAL;
		printf("door is closed\n");
	}
}
