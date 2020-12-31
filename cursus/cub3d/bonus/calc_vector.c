/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:31:17 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 13:40:34 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** @ function name: translate_vec
** @ input parameter:
**			1. position vector of player
**			2. dicection vector of player
** @ output:
** @ return : player position vector after translation
** @ brief  : rotate dir vector with theta
** @ warning:
*/

t_vecd	translate_vec(
		const t_vecd pos,
		const t_vecd dir,
		const double trans)
{
	t_vecd	ret;

	ret.x = pos.x + dir.x * trans;
	ret.y = pos.y + dir.y * trans;
	return (ret);
}

/*
** @ function name: rotate_vec
** @ input parameter:
**			1. direction vector of player
**			2. angle for rotation
** @ output:
** @ return : direction vector after rotation
** @ brief  : rotate dir vector with theta
** @ warning:
*/

t_vecd	rotate_vec(
		const t_vecd dir,
		const double theta)
{
	t_vecd	ret;

	ret.x = dir.x * cos(theta) - dir.y * sin(theta);
	ret.y = dir.x * sin(theta) + dir.y * cos(theta);
	return (ret);
}

double	calc_dist(
		const t_vecd v1,
		const t_vecd v2)
{
	t_vecd	ret;

	ret.x = fabs(v1.x - v2.x) * fabs(v1.x - v2.x);
	ret.y = fabs(v1.y - v2.y) * fabs(v1.y - v2.y);
	return (ret.x + ret.y);
}

double	calc_det(
		const t_vecd v1,
		const t_vecd v2)
{
	return (v1.x * v2.y - v2.x * v1.y);
}
