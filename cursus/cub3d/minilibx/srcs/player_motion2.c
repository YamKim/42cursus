#include "cub3d.h"

void	set_zaxis_motion(t_disp *disp, t_player *player)
{
	if (player->key & (1 << KEY_H))
		disp->hctr_bias = PLAYER_JUMP;
	else if (player->key & (1 << KEY_G))
		disp->hctr_bias = PLAYER_CROUCH;
	else
		disp->hctr_bias = 0;
}
