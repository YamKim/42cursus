#include "cub3d.h"

void	set_map_item(t_disp *disp, int y, int x)
{
	t_itm	itm;
	t_lst	*tmp;

	itm.pos.y = y + 0.5;
	itm.pos.x = x + 0.5;
	itm.tex_nbr = CONFIG_ITEM;
	tmp = lst_new_itm(itm);
	lst_add_back(&(disp->itm_lst), tmp);
	disp->itm_cnt += 1;
}

int	init_bonus_info(t_disp *disp)
{
	disp->itm_cnt = 0;
	disp->itm_lst = NULL;

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
	return (0);
}
