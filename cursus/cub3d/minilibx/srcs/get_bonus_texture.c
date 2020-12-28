/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bonus_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:55:14 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 06:07:11 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static int	get_lifebar_tex(t_disp *disp)
{
	int	ret;
	int	idx;

	ret = 0;
	idx = -1;
	if (load_tex(&(disp->tex[TEXTURE_L0]), TEXTURE_L0_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[TEXTURE_L1]), TEXTURE_L1_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[TEXTURE_L2]), TEXTURE_L2_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[TEXTURE_L3]), TEXTURE_L3_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[TEXTURE_L4]), TEXTURE_L4_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[TEXTURE_L5]), TEXTURE_L5_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[TEXTURE_LUP]), TEXTURE_LUP_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[TEXTURE_LDW]), TEXTURE_LDW_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	return (ret);
}

static int	get_attack_ani_tex(t_disp *disp)
{
	int	ret;

	ret = 0;
	if (load_tex(&(disp->ani_tex[TEXTURE_A0]), TEXTURE_A0_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->ani_tex[TEXTURE_A1]), TEXTURE_A1_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->ani_tex[TEXTURE_A2]), TEXTURE_A2_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->ani_tex[TEXTURE_A3]), TEXTURE_A3_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->ani_tex[TEXTURE_A4]), TEXTURE_A4_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	return (ret);
}

static int	bonus_sprite(t_disp *disp)
{
	int	ret;

	ret = 0;
	if (load_tex(&(disp->tex[TEXTURE_ITEM]), TEXTURE_ITEM_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (load_tex(&(disp->tex[TEXTURE_ATTACK]), TEXTURE_ATTACK_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	return (ret);
}

int			get_bonus_texture(t_disp *disp)
{
	int	ret;

	ret = 0;
	if (load_tex(&(disp->tex[TEXTURE_SECRET]), TEXTURE_SECRET_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (load_tex(&(disp->tex[TEXTURE_CLDOOR]), TEXTURE_CLDOOR_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (load_tex(&(disp->tex[TEXTURE_OPDOOR]), TEXTURE_OPDOOR_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (load_tex(&(disp->tex[TEXTURE_FLOOR]), TEXTURE_FLOOR_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (bonus_sprite(disp))
		ret = ERR_TEXTURE_CALL;
	if (get_lifebar_tex(disp))
		ret = ERR_TEXTURE_CALL;
	if (get_attack_ani_tex(disp))
		ret = ERR_TEXTURE_CALL;
	return (ret);
}
