/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:58:17 by yekim             #+#    #+#             */
/*   Updated: 2020/12/30 13:28:55 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		check_gostop(int after_map_data)
{
	if (after_map_data == MAP_WALL_VAL)
		return (0);
	else if (after_map_data == MAP_SPRITE_VAL)
		return (0);
	else if (after_map_data == MAP_OPDOOR_VAL)
		return (1);
	else if (after_map_data == MAP_CLDOOR_VAL)
		return (0);
	else if (after_map_data == MAP_ATTACK_VAL)
		return (0);
	return (1);
}

/*
** @ function name: move_forward
** @ input parameter:
**			1. information of player to use the position of player
**				and speed for translation
** @ output:
**			1. changed position of player
** @ return :
** @ brief  : move player to go forward
** @ warning:
*/

void	move_forward(t_player *player, t_map map)
{
	t_vecd	after_move;
	t_veci	after_map_data;

	after_move = translate_vec(player->pos, player->dir, player->trans_speed);
	after_map_data.y = map.data[(int)after_move.y][(int)(player->pos.x)];
	after_map_data.x = map.data[(int)(player->pos.y)][(int)after_move.x];
	if (check_gostop(after_map_data.y))
		player->pos.y = after_move.y;
	if (check_gostop(after_map_data.x))
		player->pos.x = after_move.x;
}

/*
** @ function name: move_backward
** @ input parameter:
**			1. information of player to use the position of player
**				and speed for translation
** @ output:
**			1. changed position of player
** @ return :
** @ brief  : move player to go backward
** @ warning:
*/

void	move_backward(t_player *player, t_map map)
{
	t_vecd	after_move;
	t_veci	after_map_data;

	after_move = translate_vec(player->pos, player->dir, -player->trans_speed);
	after_map_data.y = map.data[(int)after_move.y][(int)(player->pos.x)];
	after_map_data.x = map.data[(int)(player->pos.y)][(int)after_move.x];
	if (check_gostop(after_map_data.y))
		player->pos.y = after_move.y;
	if (check_gostop(after_map_data.x))
		player->pos.x = after_move.x;
}

void	move_left(t_player *player, t_map map)
{
	t_vecd	tmp_dir;
	t_vecd	after_move;
	t_veci	after_map_data;

	tmp_dir.x = player->dir.y;
	tmp_dir.y = -player->dir.x;
	after_move = translate_vec(player->pos, tmp_dir, -player->trans_speed);
	after_map_data.y = map.data[(int)after_move.y][(int)(player->pos.x)];
	after_map_data.x = map.data[(int)(player->pos.y)][(int)after_move.x];
	if (check_gostop(after_map_data.y))
		player->pos.y = after_move.y;
	if (check_gostop(after_map_data.x))
		player->pos.x = after_move.x;
}

void	move_right(t_player *player, t_map map)
{
	t_vecd	tmp_dir;
	t_vecd	after_move;
	t_veci	after_map_data;

	tmp_dir.x = player->dir.y;
	tmp_dir.y = -player->dir.x;
	after_move = translate_vec(player->pos, tmp_dir, player->trans_speed);
	after_map_data.y = map.data[(int)after_move.y][(int)(player->pos.x)];
	after_map_data.x = map.data[(int)(player->pos.y)][(int)after_move.x];
	if (check_gostop(after_map_data.y))
		player->pos.y = after_move.y;
	if (check_gostop(after_map_data.x))
		player->pos.x = after_move.x;
}
