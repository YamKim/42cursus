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

void	set_zaxis_motion(t_disp *disp, t_player *player)
{
	if (player->key & (1 << KEY_H))
		disp->hctr_bias = PLAYER_JUMP;
	else if (player->key & (1 << KEY_G))
		disp->hctr_bias = PLAYER_CROUCH;
	else
		disp->hctr_bias = 0;
}

void	open_door_trigger(t_disp *disp, t_player *player)
{
	(void)disp;
	t_vecd	door_dir;
	int		map_type;

	door_dir.y = player->pos.y + player->dir.y;
	door_dir.x = player->pos.x + player->dir.x;
	map_type = disp->map.data[(int)door_dir.y][(int)door_dir.x];
	if (map_type == MAP_CLDOOR_VAL)
	{
		disp->map.data[(int)door_dir.y][(int)door_dir.x] = MAP_OPDOOR_VAL;
		printf("door is opened\n");
	}
	if (map_type == MAP_OPDOOR_VAL)
	{
		disp->map.data[(int)door_dir.y][(int)door_dir.x] = MAP_CLDOOR_VAL;
		printf("door is closed\n");
	}
}
