#include "cub3d.h"

int	init_bonus_info(t_disp *disp)
{
	if (bonus_config(disp))
		return (ERR_BONUS_CONFIG);
	return (0);
}

int	bonus_life_bar(t_disp *disp)
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

int	bonus_config(t_disp *disp)
{
	int	ret;

	ret = 0; 
	if (load_tex(&(disp->tex[CONFIG_ITEM]), TEXTURE_ITEM_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (load_tex(&(disp->tex[CONFIG_SECRET]), TEXTURE_SECRET_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (load_tex(&(disp->tex[CONFIG_CLDOOR]), TEXTURE_CLDOOR_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (load_tex(&(disp->tex[CONFIG_OPDOOR]), TEXTURE_OPDOOR_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (load_tex(&(disp->tex[CONFIG_LOGO]), TEXTURE_HUD_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (load_tex(&(disp->tex[CONFIG_UP]), TEXTURE_UP_FILE) != 0)
		ret = ERR_TEXTURE_CALL;
	if (bonus_life_bar(disp))
		ret = ERR_TEXTURE_CALL;
	return (ret);
}
