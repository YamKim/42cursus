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

double	calc_dist(t_vecd v1, t_vecd v2)
{
	t_vecd	ret;

	ret.x = fabs(v1.x - v2.x) * fabs(v1.x - v2.x);
	ret.y = fabs(v1.y - v2.y) * fabs(v1.y - v2.y);
	
	return (ret.x + ret.y);
}

double	calc_det(t_vecd v1, t_vecd v2)
{
	return (v1.x * v2.y - v2.x * v1.y);
}
