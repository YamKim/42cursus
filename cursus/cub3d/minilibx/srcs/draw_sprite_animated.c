#include "cub3d.h"

int		is_animate_tex_range(int tex_nbr)
{
	return (tex_nbr >= CONFIG_A0 && tex_nbr <= CONFIG_A4);
}

void	control_animation_idx(t_disp *disp)
{
	if (disp->ani.upflag)
	{
		if (disp->ani.idx + 1 > MAX_ANI_IDX)
		{
			disp->ani.idx -= 1;
			disp->ani.upflag = 0;
		}
		else
			disp->ani.idx += 1;
	}
	else
	{
		if (disp->ani.idx - 1 < MIN_ANI_IDX)
		{
			disp->ani.idx += 1;
			disp->ani.upflag = 1;
		}
		else
			disp->ani.idx -= 1;
	}
}


void	animate_sprite(t_disp *disp, int tex_nbr, t_player *player)
{
	if (!is_animate_tex_range(tex_nbr))
		return ;
	time(&(player->tic[TIC_ANI].end));
	if (difftime(player->tic[TIC_ANI].end, player->tic[TIC_ANI].beg) >= 0.1)
	{
		control_animation_idx(disp);
		disp->tex[CONFIG_ATTACK] = disp->ani.tex[disp->ani.idx];
		player->tic[TIC_ANI].beg = player->tic[TIC_ANI].end;
	}
}
