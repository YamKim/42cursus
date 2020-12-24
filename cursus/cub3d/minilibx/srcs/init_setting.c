/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:19:46 by yekim             #+#    #+#             */
/*   Updated: 2020/12/23 19:05:34 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		init_tic(t_player *player)
{
	player->clk[TIC_ITEM].beg = clock() + 10000000;
	player->clk[TIC_ITEM].end = player->clk[TIC_ITEM].beg;
	player->clk[TIC_ATTACK].beg = clock() + 10000000;
	player->clk[TIC_ATTACK].end = player->clk[TIC_ATTACK].beg;
}

static void		init_player_orient(t_player *player, char orient)
{
	double	angle;

	angle = 0.0;
	if (orient == NORTH)
		angle = START_NORTH_ANGLE;
	else if (orient == EAST)
		angle = START_EAST_ANGLE;
	else if (orient == WEST)
		angle = START_WEST_ANGLE;
	else if (orient == SOUTH)
		angle = START_SOUTH_ANGLE;
	player->dir = rotate_vec(player->dir, angle * DEG2RAD);
	player->plane = rotate_vec(player->plane, angle * DEG2RAD);
}

void			init_player_setting(t_disp *disp, t_player *player)
{
	player->pos = disp->start_pos;
	player->dir.x = 0;
	player->dir.y = 1;
	player->plane.x = 0.66;
	player->plane.y = 0;
	player->key = 0;
	player->trans_speed = TRANS_SPEED;
	player->rot_speed = ROT_SPEED;
	init_player_orient(player, disp->start_orient);
	player->life = LIFE_DEFAULT;
	init_tic(player);
}

void			init_disp_setting(t_disp *disp)
{
	int	y;
	int	x;

	disp->spr_lst = NULL;
	disp->spr_cnt = 0;
	disp->start_pos.y = -1;
	disp->start_pos.x = -1;
	y = -1;
	while (++y < MAX_NUM_MAP_HEIGHT)
	{
		x = -1;
		while (++x < MAX_NUM_MAP_HEIGHT)
			disp->map.data[y][x] = MAP_UNUSED_VAL;
	}
}
