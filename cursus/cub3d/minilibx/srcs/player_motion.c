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

/*==============================================================================
** @ function name: move_forward
** @ input parameter:
**			1. information of player to use the position of player 
**				and speed for translation
** @ output:
**			1. changed position of player
** @ return :
** @ brief  : move player to go forward
** @ warning: 
===============================================================================*/
void	move_forward(t_player *player, t_map map)
{
	t_vecd	after_move;

	after_move = translate_vec(player->pos, player->dir, player->trans_speed);
    if (map.data[(int)after_move.y][(int)(player->pos.x)] != MAP_WALL_VAL)
        player->pos.y = after_move.y;
    if (map.data[(int)(player->pos.y)][(int)after_move.x] != MAP_WALL_VAL)
        player->pos.x = after_move.x;
}

/*==============================================================================
** @ function name: move_backward
** @ input parameter:
**			1. information of player to use the position of player 
**				and speed for translation
** @ output:
**			1. changed position of player
** @ return :
** @ brief  : move player to go backward
** @ warning: 
===============================================================================*/
void	move_backward(t_player *player, t_map map)
{
	t_vecd	after_move;
	
	after_move = translate_vec(player->pos, player->dir, -player->trans_speed);
    if (map.data[(int)after_move.y][(int)(player->pos.x)] != MAP_WALL_VAL)
		player->pos.y = after_move.y;
    if (map.data[(int)(player->pos.y)][(int)after_move.x] != MAP_WALL_VAL)
		player->pos.x = after_move.x;
}

/*==============================================================================
** @ function name: turn_left
** @ input parameter:
**			1. information of player to use the position of player 
**				and speed for rotation
** @ output:
**			1. direction vector of player
**			2. direction vector of plane
** @ return :
** @ brief  : turn left player's view
** @ warning: 
===============================================================================*/
void	turn_left(t_player *player)
{
	player->dir = rotate_vec(player->dir, player->rot_speed);	
	player->plane = rotate_vec(player->plane, player->rot_speed);
}

/*==============================================================================
** @ function name: turn_right
** @ input parameter:
**			1. information of player to use the position of player 
**				and speed for rotation
** @ output:
**			1. direction vector of player
**			2. direction vector of plane
** @ return :
** @ brief  : turn right player's view
** @ warning: 
===============================================================================*/
void	turn_right(t_player *player)
{
	player->dir = rotate_vec(player->dir, -player->rot_speed);	
	player->plane = rotate_vec(player->plane, -player->rot_speed);
}
