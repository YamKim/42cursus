#include "cub3d.h"

extern int	world_map[MAP_WIDTH][MAP_HEIGHT];

typedef struct		s_dda
{
	t_vecd			side_dist;
	t_vecd			delta_dist;
	t_veci			step;
	int				hit;
	int				side;
}					t_dda;

double	dda_algorithm(t_player *player, const t_vecd ray_dir)
{
	t_dda	dda;
	int		hit;
	double	perpWallDist;
	t_veci	map;

	map = player->map;

	dda.delta_dist.x = fabs(1 / ray_dir.x);
	dda.delta_dist.y = fabs(1 / ray_dir.y);
	hit = 0;
	
	if (ray_dir.x < 0)
	{
		dda.step.x = -1;
		dda.side_dist.x = (player->pos.x - map.x) * dda.delta_dist.x;
	}
	else
	{
		dda.step.x = 1;
		dda.side_dist.x = (map.x + 1.0 - player->pos.x) * dda.delta_dist.x;
	}
	if (ray_dir.y < 0)
    {
		dda.step.y = -1;
		dda.side_dist.y = (player->pos.y - map.y) * dda.delta_dist.y;
	}
	else
	{
		dda.step.y = 1;
		dda.side_dist.y = (map.y + 1.0 - player->pos.y) * dda.delta_dist.y;
	}
	
	while (hit == 0)
	{
		if (dda.side_dist.x < dda.side_dist.y)
		{
			dda.side_dist.x += dda.delta_dist.x;
			map.x += dda.step.x;
			dda.side = 0;
		}
		else
		{
			dda.side_dist.y += dda.delta_dist.y;
			map.y += dda.step.y;
			dda.side = 1;
		}
		if (world_map[map.x][map.y] > 0)
			hit = 1;
	}

	if (dda.side == 0)
		perpWallDist = (map.x - player->pos.x + (double)(1 - dda.step.x) / 2) / ray_dir.x;
	else
		perpWallDist = (map.y - player->pos.y + (double)(1 - dda.step.y) / 2) / ray_dir.y;

	return (perpWallDist);
}
