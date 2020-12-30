/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 10:15:04 by yekim             #+#    #+#             */
/*   Updated: 2020/12/30 10:15:04 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** @ function name: turn_left
** @ input parameter:
**			1. information of player to use the position of player
**				and speed for rotation
** @ output:
**			1. direction vector of player
**			2. direction vector of plane
** @ return :
** @ brief  : turn left player's view
** @ warning:
*/

void	turn_left(t_player *player)
{
	player->dir = rotate_vec(player->dir, player->rot_speed);
	player->plane = rotate_vec(player->plane, player->rot_speed);
}

/*
** @ function name: turn_right
** @ input parameter:
**			1. information of player to use the position of player
**				and speed for rotation
** @ output:
**			1. direction vector of player
**			2. direction vector of plane
** @ return :
** @ brief  : turn right player's view
** @ warning:
*/

void	turn_right(t_player *player)
{
	player->dir = rotate_vec(player->dir, -player->rot_speed);
	player->plane = rotate_vec(player->plane, -player->rot_speed);
}
