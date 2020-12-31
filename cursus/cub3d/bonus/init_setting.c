/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:19:46 by yekim             #+#    #+#             */
/*   Updated: 2020/12/31 18:04:32 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

static void		init_player_setting_bonus(t_player *player)
{
	player->life = LIFE_DEFAULT;
	player->clk[TIC_ITEM].beg = clock() - INT_MAX;
	player->clk[TIC_ITEM].end = player->clk[TIC_ITEM].beg;
	player->clk[TIC_ATTACK].beg = clock() - INT_MAX;
	player->clk[TIC_ATTACK].end = player->clk[TIC_ATTACK].beg;
	player->sound = clock();
	system("afplay -v 0.30 ./sound/maintheme.mp3 &>/dev/null &");
}

void			init_player_setting(t_disp *disp, t_player *player)
{
	player->pos = disp->start_pos;
	player->dir.x = 0;
	player->dir.y = 1;
	player->plane.x = 0.66;
	player->plane.y = 0;
	player->key = 0;
	player->mouse = 0;
	player->trans_speed = TRANS_SPEED;
	player->rot_speed = ROT_SPEED;
	init_player_orient(player, disp->start_orient);
	init_player_setting_bonus(player);
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

t_loop			set_loop_val(
				t_disp *dp,
				t_player *player)
{
	t_loop	ret;

	dp->mlx_ptr = mlx_init();
	dp->win_ptr = mlx_new_window(dp->mlx_ptr, dp->w, dp->h, "mlx");
	dp->img.ptr = mlx_new_image(dp->mlx_ptr, dp->w, dp->h);
	dp->img.data = (int *)mlx_get_data_addr(dp->img.ptr,\
						&(dp->img.bpp), &(dp->img.size_l), &(dp->img.endian));
	dp->img.w = dp->w;
	dp->img.h = dp->h;
	init_setting_bonus(dp);
	ret.disp = dp;
	ret.player = player;
	return (ret);
}
