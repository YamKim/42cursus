#include "cub3d.h"

int		is_animate_tex_range(int tex_nbr)
{
	return (tex_nbr >= CONFIG_A0 && tex_nbr <= CONFIG_A4);
}

void	control_animation_idx(t_spr *spr)
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


void	animate_sprite(t_spr *spr, t_disp *disp, int tex_nbr)
{
#if 0
	if (!is_animate_tex_range(tex_nbr))
		return ;
#endif
	(void)tex_nbr;
#if 0
	if (spr->tex != &(disp->tex[CONFIG_ATTACK]))
		return ;
#endif
#if 1
	if (spr->tex_nbr != CONFIG_ATTACK)
		return ;
#endif
	time(&(spr->tic.end));
	if (difftime(spr->tic.end, spr->tic.beg) >= 0.1)
	{
		control_animation_idx(spr);
		spr->tex = &(disp->ani.tex[spr->ani.idx]);
		spr->tic.beg = spr->tic.end;
	}
}
