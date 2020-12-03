#include "cub3d.h"

void	get_close_item(t_disp *disp, t_player *p)
{
	int		i;
	t_itm	itm;

	i = -1;
	while (++i < disp->itm_cnt)
	{
		itm = lst_get_idx(disp->itm_lst, i)->itm;
		if (fabs(calc_dist(p->pos, itm.pos)) < ITEM_APPROACH_DIST)
		{
			lst_del_idx(&disp->itm_lst, i);	
			disp->itm_cnt = disp->itm_cnt - 1;
			--i;	
			printf("You got an item!\n");
		}
	}	
}
