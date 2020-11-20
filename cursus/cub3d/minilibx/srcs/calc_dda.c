/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 07:13:45 by yekim             #+#    #+#             */
/*   Updated: 2020/11/20 10:57:11 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern int world_map[MAP_WIDTH][MAP_HEIGHT];
t_veci	get_step(const t_vecd ray_dir)
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

t_vecd	get_delta_dist(const t_vecd ray_dir)
{
	t_vecd	ret;

	if (ray_dir.y == 0.0)
		ret.x = 0.0;
	else
	{
		if (ray_dir.x == 0.0)
			ret.x = 1.0;
		else
			ret.x = fabs(1 / ray_dir.x);
	}
	if (ray_dir.x == 0.0)
		ret.y = 0.0;
	else
	{
		if (ray_dir.y == 0)
			ret.y = 1.0;
		else
			ret.y = fabs(1 / ray_dir.y);
	}
	return (ret);
}

t_vecd	get_side_dist(
		const t_player *player,
		const t_dda dda,
		const t_veci hit_point)
{
	t_vecd	ret;

	if (dda.ray_dir.x < 0.0)
		ret.x = (player->pos.x - hit_point.x) * dda.delta_dist.x;
	else
		ret.x = (hit_point.x + 1.0 - player->pos.x) * dda.delta_dist.x;
	if (dda.ray_dir.y < 0.0)
		ret.y = (player->pos.y - hit_point.y) * dda.delta_dist.y;
	else
		ret.y = (hit_point.y + 1.0 - player->pos.y) * dda.delta_dist.y;
	return (ret);
}

int		dda_run(const t_dda dda, t_veci *hit_point)
{
	int		hit;
	int		ret;
	t_vecd	ray_dist;

	hit = 0;
	ray_dist.x = dda.side_dist.x;
	ray_dist.y = dda.side_dist.y;
	while (hit == 0)
	{
		if (ray_dist.x < ray_dist.y)
		{
			ray_dist.x = ray_dist.x + dda.delta_dist.x;
			hit_point->x += dda.step.x;
			ret = 0;
		}
		else
		{
			ray_dist.y = ray_dist.y + dda.delta_dist.y;
			hit_point->y += dda.step.y;
			ret = 1;
		}
		if (world_map[hit_point->x][hit_point->y] > 0)
			hit = 1;
	}
	return (ret);
}

double	dda_algorithm(
		const t_player *player,
		const t_vecd ray_dir,
		t_veci *hit_point,
		int *side)
{
	t_dda	dda;
	double	ret;

	dda.ray_dir = ray_dir;
	dda.delta_dist = get_delta_dist(dda.ray_dir);
	dda.step = get_step(dda.ray_dir);
	dda.side_dist = get_side_dist(player, dda, *hit_point);
	*side = dda_run(dda, hit_point);
	if (*side == 0)
	{
		ret = (hit_point->x - player->pos.x + (double)(1 - dda.step.x) / 2);
		ret = ret / dda.ray_dir.x;
	}
	else
	{
		ret = (hit_point->y - player->pos.y + (double)(1 - dda.step.y) / 2);
		ret = ret / dda.ray_dir.y;
	}
	return (ret);
}
