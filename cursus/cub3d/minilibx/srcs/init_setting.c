#include "cub3d.h"

void	start_orient(t_player *player, char orient)
{
	double	angle;

	angle = 0.0;
	if (orient == NORTH)
		angle = START_NORTH_ANGLE;
	else if (orient == EAST)
		angle = START_EAST_ANGLE;
	else if (orient == WEST)
		angle = START_WEST_ANGLE;
	else if (orient == SOUTH)
		angle = START_SOUTH_ANGLE;
	player->dir = rotate_vec(player->dir, angle * DEG2RAD);
	player->plane = rotate_vec(player->plane, angle * DEG2RAD);
}

void init_player_setting(t_disp *disp, t_player *player)
{
	player->pos = disp->start_pos;
	player->dir.x = 0;
	player->dir.y = 1;
	player->plane.x = 0.66;
	player->plane.y = 0;
	player->key = 0;
	player->trans_speed = TRANS_SPEED;
	player->rot_speed = ROT_SPEED;
	start_orient(player, disp->start_orient);
}

void	init_disp_setting(t_disp *disp)
{
	disp->spr_lst = NULL;
}
