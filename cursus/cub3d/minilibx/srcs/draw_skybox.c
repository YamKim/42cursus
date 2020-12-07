#include "cub3d.h"

int	set_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_skybox_color(t_map *map, t_veci idx, t_veci step)
{
	int	ret;

	ret = set_color(255, 0, 0, 0);
	if (map->data[idx.y / step.y][idx.x / step.x] == MAP_WALL_VAL)
		ret = COLOR_SKY_TRANSPARENCY | COLOR_SKY_WALL;
	else if (map->data[idx.y / step.y][idx.x / step.x] == MAP_ROAD_VAL)
		ret = COLOR_SKY_TRANSPARENCY | COLOR_SKY_ROAD;
	else if (map->data[idx.y / step.y][idx.x / step.x] == MAP_ITEM_VAL)
		ret = COLOR_SKY_TRANSPARENCY | COLOR_SKY_ITEM;
	else if (map->data[idx.y / step.y][idx.x / step.x] == MAP_SECRET_VAL)
		ret = COLOR_SKY_TRANSPARENCY | COLOR_SKY_SECRET;
	else if (map->data[idx.y / step.y][idx.x / step.x] == MAP_SPRITE_VAL)
		ret = COLOR_SKY_TRANSPARENCY | COLOR_SKY_SPRITE;
	return (ret);
}

int	draw_skybox(t_disp *disp, t_player player)
{
	t_img	skybox;
	t_veci	idx;
	t_veci	step;

	(void)player;
	skybox.w = disp->w * DISP2SKYW;
	skybox.h = disp->h * DISP2SKYH;
	skybox.ptr = mlx_new_image(disp->mlx_ptr, skybox.w, skybox.h);
	skybox.data = (int *)mlx_get_data_addr(skybox.ptr, &(skybox.bpp),
				&(skybox.size_l), &(skybox.endian));
	step.x = skybox.w / disp->map.max_w;
	step.y = skybox.h / disp->map.h;
	for (int x = 0; x < skybox.w; ++x) {
		for (int y = 0; y < skybox.h; ++y) {
			idx.x = x;
			idx.y = y;
			skybox.data[(skybox.h - 1 - y) * skybox.w + x] = \
				get_skybox_color(&(disp->map), idx, step);
		}
	}
	mlx_put_image_to_window(disp->mlx_ptr, disp->win_ptr, skybox.ptr, 0, 0);
	return (0);
}
