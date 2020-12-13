#include "cub3d.h"

int	init_bonus_info(t_disp *disp)
{
	if (bonus_config(disp))
		return (ERR_BONUS_CONFIG);
	return (0);
}

int	get_lifebar_tex(t_disp *disp)
{
	int	ret;

	ret = 0;
	if (load_tex(&(disp->tex[CONFIG_L0]), TEXTURE_L0_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[CONFIG_L1]), TEXTURE_L1_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[CONFIG_L2]), TEXTURE_L2_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[CONFIG_L3]), TEXTURE_L3_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[CONFIG_L4]), TEXTURE_L4_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[CONFIG_L5]), TEXTURE_L5_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	return (ret);
}

int	get_animation_tex(t_disp *disp)
{
	int	ret;

	ret = 0;
	if (load_tex(&(disp->ani.tex[CONFIG_A0]), TEXTURE_A0_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->ani.tex[CONFIG_A1]), TEXTURE_A1_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->ani.tex[CONFIG_A2]), TEXTURE_A2_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->ani.tex[CONFIG_A3]), TEXTURE_A3_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->ani.tex[CONFIG_A4]), TEXTURE_A4_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	return (ret);
}

int	bonus_sprite(t_disp *disp)
{
	int	ret;

	ret = 0;
	if (load_tex(&(disp->tex[CONFIG_ITEM]), TEXTURE_ITEM_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (load_tex(&(disp->tex[CONFIG_ATTACK]), TEXTURE_ATTACK_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (get_animation_tex(disp))
		ret = ERR_TEXTURE_CALL;
	return (ret);
}

int	bonus_config(t_disp *disp)
{
	int	ret;

	ret = 0; 
	if (load_tex(&(disp->tex[CONFIG_SECRET]), TEXTURE_SECRET_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (load_tex(&(disp->tex[CONFIG_CLDOOR]), TEXTURE_CLDOOR_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (load_tex(&(disp->tex[CONFIG_OPDOOR]), TEXTURE_OPDOOR_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (load_tex(&(disp->tex[CONFIG_UP]), TEXTURE_UP_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (get_lifebar_tex(disp))
		ret = ERR_TEXTURE_CALL;
	if (bonus_sprite(disp))
		ret = ERR_TEXTURE_CALL;
	return (ret);
}
