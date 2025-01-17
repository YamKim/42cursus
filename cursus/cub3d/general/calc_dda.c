/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 07:13:45 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 13:40:30 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** @ function name: get_step
** @ input parameter:
**			1. direction vector of ray
** @ output:
** @ return : step which is decide
** @ brief  : decide the step direction for dda algorithm
** @ warning:
*/

static t_veci	get_step(const t_vecd ray_dir)
{
	t_veci	ret;

	if (ray_dir.x < 0.0)
		ret.x = -1;
	else
		ret.x = 1;
	if (ray_dir.y < 0.0)
		ret.y = -1;
	else
		ret.y = 1;
	return (ret);
}

/*
** @ function name: get_delta_dist
** @ input parameter:
**			1. direction vector of ray
** @ output:
**
** @ return : delta distance. ray distance between x sides or y sides
** @ brief  : calculate delta distance for accumulating ray distance.
** @ warning:
*/

static t_vecd	get_delta_dist(const t_vecd ray_dir)
{
	t_vecd	ret;

	if (fabs(ray_dir.y - 0.0) < EPSILON)
		ret.x = 0.0;
	else
	{
		if (fabs(ray_dir.x - 0.0) < EPSILON)
			ret.x = 1.0;
		else
			ret.x = fabs(1 / ray_dir.x);
	}
	if (fabs(ray_dir.x - 0.0) < EPSILON)
		ret.y = 0.0;
	else
	{
		if (fabs(ray_dir.y - 0.0) < EPSILON)
			ret.y = 1.0;
		else
			ret.y = fabs(1 / ray_dir.y);
	}
	return (ret);
}

/*
** @ function name: get_side_dist
** @ input parameter:
**			1. information of player for using position of player
**			2. information of dda including values related with ray distance
**			3. hit point which is changed as ray keeps straight
** @ output:
** @ return : side distance. distance between player and first x side or y side
** @ brief  : calculate side distance based on ray distance.
** @ warning:
*/

static t_vecd	get_side_dist(
				const t_player *player,
				const t_dda dda,
				const t_hit hit_point)
{
	t_vecd	ret;

	if (dda.ray_dir.x < 0.0)
		ret.x = (player->pos.x - hit_point.pos.x) * dda.delta_dist.x;
	else
		ret.x = (hit_point.pos.x + 1.0 - player->pos.x) * dda.delta_dist.x;
	if (dda.ray_dir.y < 0.0)
		ret.y = (player->pos.y - hit_point.pos.y) * dda.delta_dist.y;
	else
		ret.y = (hit_point.pos.y + 1.0 - player->pos.y) * dda.delta_dist.y;
	return (ret);
}

/*
** @ function name: run_dda_algorithm
** @ input parameter:
**			1. information of dda for using side/delta distance, step
**			2. hit point which is changed as ray keeps straight
** @ output:
**			1. changed position of hit point.
**			2. side hit by ray (x side: return 0, y side: return 1)
** @ return :
** @ brief  : run algorithm accumulating ray distance until finding hit spot.
** @ warning:
*/

static void		run_dda_algorithm(
				t_dda dda,
				t_hit *hp,
				const t_map map)
{
	int		hit_flag;

	hit_flag = 0;
	while (hit_flag == 0)
	{
		if (dda.side_dist.x < dda.side_dist.y)
		{
			dda.side_dist.x = dda.side_dist.x + dda.delta_dist.x;
			hp->pos.x += dda.step.x;
			hp->side = HIT_SIDE_X;
		}
		else
		{
			dda.side_dist.y = dda.side_dist.y + dda.delta_dist.y;
			hp->pos.y += dda.step.y;
			hp->side = HIT_SIDE_Y;
		}
		hit_flag = check_door_type(hp, map.data[hp->pos.y][hp->pos.x]);
	}
}

/*
** @ function name: dda_algorithm
** @ input parameter:
**			1. information of player to use the position of player and ray dir
** @ output:
**			1. changed position of hit point and side of hit spot.
** @ return : perpendicular distance between player and wall.
** @ brief  : set values and run dda algorithm to obtain hit spot and perp dist.
** @ warning:
*/

double			dda_algorithm(
				t_player *player,
				t_hit *hp,
				t_map map)
{
	t_dda	dda;
	double	ret;

	dda.ray_dir = player->ray_dir;
	dda.delta_dist = get_delta_dist(dda.ray_dir);
	dda.step = get_step(dda.ray_dir);
	dda.side_dist = get_side_dist(player, dda, *hp);
	run_dda_algorithm(dda, hp, map);
	if (hp->side == HIT_SIDE_X)
	{
		ret = (hp->pos.x - player->pos.x + (double)(1 - dda.step.x) / 2);
		ret = ret / dda.ray_dir.x;
	}
	else
	{
		ret = (hp->pos.y - player->pos.y + (double)(1 - dda.step.y) / 2);
		ret = ret / dda.ray_dir.y;
	}
	return (ret);
}
