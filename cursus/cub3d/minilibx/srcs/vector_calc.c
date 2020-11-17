#include "cub3d.h"

t_vecd	translate_vec(t_vecd pos, t_vecd dir, double trans)
{
	t_vecd	ret;

	ret.x = pos.x - dir.x * trans;
	ret.y = pos.y - dir.y * trans;
	return (ret);
}

t_vecd	rotate_vec(t_vecd dir, double theta)
{
	t_vecd	ret;

	ret.x = dir.x * cos(theta) - dir.y * sin(theta);
	ret.y = dir.y * sin(theta) + dir.y * cos(theta);
	return (ret);
}
