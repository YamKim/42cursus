#include "cub3d.h"

/*==============================================================================
** @ function name: translate_vec
** @ input parameter:
**			1. position vector of player
**			2. dicection vector of player
** @ output:
**
** @ return : player position vector after translation
** @ brief  : rotate dir vector with theta
** @ warning: 
===============================================================================*/
t_vecd	translate_vec(t_vecd pos, t_vecd dir, double trans)
{
	t_vecd	ret;

	ret.x = pos.x + dir.x * trans;
	ret.y = pos.y + dir.y * trans;
	return (ret);
}

/*==============================================================================
** @ function name: rotate_vec
** @ input parameter:
**			1. direction vector of player
**			2. angle for rotation 
** @ output:
**
** @ return : direction vector after rotation
** @ brief  : rotate dir vector with theta
** @ warning: 
===============================================================================*/
t_vecd	rotate_vec(t_vecd dir, double theta)
{
	t_vecd	ret;

	ret.x = dir.x * cos(theta) - dir.y * sin(theta);
	ret.y = dir.x * sin(theta) + dir.y * cos(theta);
	return (ret);
}
