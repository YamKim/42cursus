/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:39:30 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 06:07:21 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static int	set_attack_animation(t_disp *disp, t_spr *spr, int tex_nbr)
{
	int	idx;

	spr->tex_nbr = tex_nbr;
	spr->tex = &(disp->tex[spr->tex_nbr]);
	spr->ani.upflag = 1;
	spr->ani.idx = 0;
	spr->clk.beg = clock();
	spr->clk.end = spr->clk.beg;
	idx = -1;
	while (++idx < TEXTURE_ANI_NUMBER)
		spr->ani.tex[idx] = disp->ani_tex[idx];
	return (MAP_ATTACK_VAL);
}

static int	set_no_animation(t_disp *disp, t_spr *spr, int tex_nbr)
{
	spr->tex_nbr = tex_nbr;
	spr->tex = &(disp->tex[spr->tex_nbr]);
	if (tex_nbr == CONFIG_S)
		return (MAP_SPRITE_VAL);
	else if (tex_nbr == TEXTURE_ITEM)
		return (MAP_ITEM_VAL);
	return (0);
}

int			set_animation(t_disp *disp, t_spr *spr, char data)
{
	int	ret;

	ret = 0;
	if (data == MAP_SPRITE)
		ret = set_no_animation(disp, spr, CONFIG_S);
	else if (data == MAP_ITEM)
		ret = set_no_animation(disp, spr, TEXTURE_ITEM);
	else if (data == MAP_ATTACK)
		ret = set_attack_animation(disp, spr, TEXTURE_ATTACK);
	return (ret);
}
