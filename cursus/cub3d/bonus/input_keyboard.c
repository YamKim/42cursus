/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:23:35 by yekim             #+#    #+#             */
/*   Updated: 2020/12/30 13:26:22 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		key_press(int key, t_loop *lv)
{
	if (key == KEY_ESC)
		finish_program(lv);
	else if (key == KEY_W)
		lv->player->key |= (1 << MOVE_W);
	else if (key == KEY_S)
		lv->player->key |= (1 << MOVE_S);
	else if (key == KEY_A)
		lv->player->key |= (1 << MOVE_A);
	else if (key == KEY_D)
		lv->player->key |= (1 << MOVE_D);
	else if (key == KEY_LEFT)
		lv->player->key |= (1 << MOVE_LEFT);
	else if (key == KEY_RIGHT)
		lv->player->key |= (1 << MOVE_RIGHT);
	else if (key == KEY_H)
		lv->player->key |= (1 << MOVE_H);
	else if (key == KEY_G)
		lv->player->key |= (1 << MOVE_G);
	else if (key == KEY_F)
		open_door_trigger(lv->disp, lv->player);
	return (0);
}

int		key_release(int key, t_loop *lv)
{
	if (key == KEY_ESC)
		finish_program(lv);
	else if (key == KEY_W)
		lv->player->key &= ~(1 << MOVE_W);
	else if (key == KEY_S)
		lv->player->key &= ~(1 << MOVE_S);
	else if (key == KEY_A)
		lv->player->key &= ~(1 << MOVE_A);
	else if (key == KEY_D)
		lv->player->key &= ~(1 << MOVE_D);
	else if (key == KEY_LEFT)
		lv->player->key &= ~(1 << MOVE_LEFT);
	else if (key == KEY_RIGHT)
		lv->player->key &= ~(1 << MOVE_RIGHT);
	else if (key == KEY_H)
		lv->player->key &= ~(1 << MOVE_H);
	else if (key == KEY_G)
		lv->player->key &= ~(1 << MOVE_G);
	return (0);
}

void	key_update(t_loop *lv)
{
	if (lv->player->key & (1 << MOVE_W))
		move_forward(lv->player, lv->disp->map);
	if (lv->player->key & (1 << MOVE_S))
		move_backward(lv->player, lv->disp->map);
	if (lv->player->key & (1 << MOVE_A))
		move_left(lv->player, lv->disp->map);
	if (lv->player->key & (1 << MOVE_D))
		move_right(lv->player, lv->disp->map);
	if (lv->player->key & (1 << MOVE_LEFT))
		turn_left(lv->player);
	if (lv->player->key & (1 << MOVE_RIGHT))
		turn_right(lv->player);
	set_zaxis_motion(lv->disp, lv->player);
}
