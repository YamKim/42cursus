/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:39:30 by yekim             #+#    #+#             */
/*   Updated: 2020/12/31 18:08:51 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	return (ret);
}
