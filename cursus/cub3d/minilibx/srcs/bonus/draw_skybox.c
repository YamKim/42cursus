/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_skybox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:51:50 by yekim             #+#    #+#             */
/*   Updated: 2020/12/31 08:53:17 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_img	set_skybox_img(const t_disp *disp)
{
	t_img	ret;
	int		tmp;

	ret.w = disp->w * DISP2SKYW;
	ret.h = disp->h * DISP2SKYH;
	ret.ptr = mlx_new_image(disp->mlx_ptr, ret.w, ret.h);
	ret.data = (int *)mlx_get_data_addr(ret.ptr, &tmp, &tmp, &tmp);
	return (ret);
}

static int		get_skybox_color(
				const t_map *map,
				const t_veci idx,
				const t_veci step)
{
	int	ret;

	ret = COLOR_SKY_BACKBACKGROUND;
	if (map->data[idx.y / step.y][idx.x / step.x] == MAP_WALL_VAL)
		ret = COLOR_SKY_BACKGROUND | COLOR_SKY_WALL;
	else if (map->data[idx.y / step.y][idx.x / step.x] == MAP_ROAD_VAL)
		ret = COLOR_SKY_BACKGROUND | COLOR_SKY_ROAD;
	else if (map->data[idx.y / step.y][idx.x / step.x] == MAP_ITEM_VAL)
		ret = COLOR_SKY_BACKGROUND | COLOR_SKY_ITEM;
	else if (map->data[idx.y / step.y][idx.x / step.x] == MAP_SECRET_VAL)
		ret = COLOR_SKY_BACKGROUND | COLOR_SKY_SECRET;
	else if (map->data[idx.y / step.y][idx.x / step.x] == MAP_SPRITE_VAL)
		ret = COLOR_SKY_BACKGROUND | COLOR_SKY_SPRITE;
	else if (map->data[idx.y / step.y][idx.x / step.x] == MAP_ATTACK_VAL)
		ret = COLOR_SKY_BACKGROUND | COLOR_SKY_ATTACK;
	else if (map->data[idx.y / step.y][idx.x / step.x] == MAP_OPDOOR_VAL
			|| map->data[idx.y / step.y][idx.x / step.x] == MAP_CLDOOR_VAL)
		ret = COLOR_SKY_BACKGROUND | COLOR_SKY_OPCLDOOR;
	return (ret);
}

static void		draw_skybox_point(
				t_img *skybox,
				const t_vecd p,
				const int color,
				const int size)
{
	int	x;
	int	y;

	x = p.x - size - 1;
	y = p.y - size - 1;
	while (++x <= p.x + size)
		while (++y <= p.y + size)
			skybox->data[(skybox->h - 1 - y) * skybox->w + x] = color;
}

static void		draw_skybox_player(
				const t_disp *disp,
				t_img *skybox,
				const t_player *p)
{
	int		i;
	t_vecd	point;
	t_vecd	d[5];
	t_vecd	ray_l[5];
	t_vecd	ray_r[5];

	point.x = (double)p->pos.x * skybox->w / disp->map.max_w;
	point.y = (double)p->pos.y * skybox->h / disp->map.h;
	i = -1;
	while (++i < 5)
	{
		d[i].x = point.x + 3 * i * p->dir.x;
		d[i].y = point.y + 3 * i * p->dir.y;
		ray_l[i].y = point.y + 3 * i * (p->dir.y + p->plane.y);
		ray_l[i].x = point.x + 3 * i * (p->dir.x + p->plane.x);
		ray_r[i].y = point.y + 3 * i * (p->dir.y - p->plane.y);
		ray_r[i].x = point.x + 3 * i * (p->dir.x - p->plane.x);
		draw_skybox_point(skybox, d[i], COLOR_SKY_DIR, 1);
		draw_skybox_point(skybox, ray_l[i], COLOR_SKY_RAY_DIR, 1);
		draw_skybox_point(skybox, ray_r[i], COLOR_SKY_RAY_DIR, 1);
	}
	draw_skybox_point(skybox, point, COLOR_SKY_PLAYER, SIZE_SKY_PLAYER);
}

int				draw_skybox(
				t_disp *disp,
				t_player *player)
{
	t_img	skybox;
	t_veci	idx;
	t_veci	step;

	skybox = set_skybox_img(disp);
	step.x = skybox.w / disp->map.max_w;
	step.y = skybox.h / disp->map.h;
	idx.x = -1;
	while (++(idx.x) < skybox.w)
	{
		idx.y = -1;
		while (++(idx.y) < skybox.h)
		{
			skybox.data[(skybox.h - 1 - idx.y) * skybox.w + idx.x] = \
				get_skybox_color(&(disp->map), idx, step);
		}
	}
	draw_skybox_player(disp, &skybox, player);
	mlx_put_image_to_window(disp->mlx_ptr, disp->win_ptr, skybox.ptr, 0, 0);
	free(skybox.ptr);
	free(skybox.data);
	return (0);
}
