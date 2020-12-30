#include "../include/cub3d.h"

static int		draw_main(
				t_disp *disp,
				t_player *player,
				double *perp_buf,
				int secret)
{
	t_hit	hp;
	int		t;
	double	camera_t;

	t = -1;
	hp.secret_door = secret;
	while (++t < disp->w)
	{
		hp.pos.x = (int)(player->pos.x);
		hp.pos.y = (int)(player->pos.y);
		camera_t = (2 * t / (double)(disp->w)) - 1;
		player->ray_dir.x = player->dir.x + player->plane.x * camera_t;
		player->ray_dir.y = player->dir.y + player->plane.y * camera_t;
		hp.perp_wall_dist = dda_algorithm(player, &hp, disp->map);
		draw_tex_wall(disp, player, t, &hp);
		perp_buf[t] = hp.perp_wall_dist;
	}
	draw_sprite(disp, player, perp_buf);
	mlx_put_image_to_window(disp->mlx_ptr, disp->win_ptr, disp->img.ptr, 0, 0);
	return (0);
}

int				run_raycasting(t_loop *lv)
{
	double	*perp_buf;
	int		ret;

	ret = 0;
	if (!(perp_buf = (double *)malloc(sizeof(double) * lv->disp->w)))
		return (ERR_MALLOC);
	(void)draw_main;
	if (ret == 0 && draw_background(lv->disp, lv->player))
		ret |= ERR_DRAW_IMG;
	if (ret == 0 && draw_main(lv->disp, lv->player, perp_buf, 0))
		ret |= ERR_DRAW_IMG;
	if (ret == 0 && draw_main(lv->disp, lv->player, perp_buf, 1))
		ret |= ERR_DRAW_IMG;
	if (ret == 0 && draw_skybox(lv->disp, lv->player))
		ret |= ERR_DRAW_IMG;
	if (draw_hud_series(lv->disp, lv->player))
		ret |= ERR_DRAW_IMG;
	key_update(lv);
	free(perp_buf);
	if (lv->player->life == MIN_LIFE)
		finish_program(lv);
	return (ret);
}

