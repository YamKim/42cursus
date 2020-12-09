#include "cub3d.h"

int	init_bonus_info(t_disp *disp)
{
	if (bonus_config(disp))
		return (ERR_BONUS_CONFIG);
	return (0);
}


int	bonus_config(t_disp *disp)
{
	if (load_tex(&(disp->tex[CONFIG_ITEM]), TEXTURE_ITEM_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[CONFIG_SECRET]), TEXTURE_SECRET_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[CONFIG_OPDOOR]), TEXTURE_OPDOOR_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	if (load_tex(&(disp->tex[CONFIG_HUD]), TEXTURE_HUD_FILE) != 0)
		return (ERR_TEXTURE_CALL);
	return (0);
}
