/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:08:12 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 13:54:41 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		control_animation_idx(t_spr *spr)
{
	if (spr->ani.upflag)
	{
		if (spr->ani.idx + 1 > MAX_ANI_IDX)
		{
			spr->ani.idx -= 1;
			spr->ani.upflag = 0;
		}
		else
			spr->ani.idx += 1;
	}
	else
	{
		if (spr->ani.idx - 1 < MIN_ANI_IDX)
		{
			spr->ani.idx += 1;
			spr->ani.upflag = 1;
		}
		else
			spr->ani.idx -= 1;
	}
}

static void		animate_attack(t_spr *spr)
{
	spr->clk.end = clock();
	if (spr->clk.end - spr->clk.beg >= 500000)
	{
		control_animation_idx(spr);
		spr->tex = &(spr->ani.tex[spr->ani.idx]);
		spr->clk.beg = spr->clk.end;
	}
}

void			animate_sprite(t_spr *spr)
{
	if (spr->tex_nbr != TEXTURE_ATTACK)
		return ;
	if (spr->tex_nbr == TEXTURE_ATTACK)
		animate_attack(spr);
}
