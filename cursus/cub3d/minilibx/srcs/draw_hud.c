#include "cub3d.h"

void	init_hud_img(t_img *hud)
{
	int	x;
	int	y;

	x = -1;
	while (++x < hud->w)
	{
		y = -1;
		while (++y < hud->h)
			hud->data[y * hud->w + x] = 0xFF000000;
	}
}

t_draw	set_hud_draw(t_img *hud)
{
	t_draw	ret;
	
	ret.xctr = (int)((double)hud->w / 2);
	ret.yctr = (int)((double)hud->h / 2);

	ret.lh = hud->h;
	ret.xbeg = (int)fmax(ret.xctr - (double)hud->w / 2, 0);
	ret.xend = (int)fmin(ret.xctr + (double)hud->w / 2, hud->w - 1);
	ret.ybeg = (int)fmax(ret.yctr - (double)hud->h / 2, 0);
	ret.yend = (int)fmin(ret.yctr + (double)hud->h / 2, hud->h - 1);
	return (ret);
}

t_img	set_hud_img(t_disp *disp)
{
	t_img	ret;
	int		tmp;

	ret.w =	(int)disp->w * DISP2HUDW;
	ret.h =	(int)disp->h * DISP2HUDH;
	ret.ptr = mlx_new_image(disp->mlx_ptr, ret.w, ret.h);
	ret.data = (int *)mlx_get_data_addr(ret.ptr, &tmp, &tmp, &tmp);

	return (ret);
}

void	draw_hud_part(t_img *hud, t_draw *draw, t_tex tex)
{
	t_vecd	tpos;
	t_vecd	step;

	step.x = (double)tex.w / hud->w;
	step.y = (double)tex.h / hud->h;
	draw->x = draw->xbeg - 1;
	while (++(draw->x) < draw->xend)
	{
		tpos.x = draw->x - draw->xctr + (double)hud->w / 2;
		draw->tx = (int)fmin(tpos.x * step.x, tex.w - 1);	
		draw->y = draw->ybeg - 1;
		while (++(draw->y) < draw->yend)
		{
			tpos.y = draw->y - draw->yctr + (double)hud->h / 2;
			draw->ty = (int)fmin(tpos.y * step.y, tex.h - 1);
			draw->color = tex.data[draw->ty * tex.w + draw->tx];	
			hud->data[draw->y * hud->w + draw->x] = draw->color;
		}
	}

}

int	draw_hud(t_disp *disp, t_player *player, t_tex tex, t_veci b)
{
	t_img	hud;
	t_draw	draw;

	(void)player;
	hud = set_hud_img(disp);
	init_hud_img(&hud);
	draw = set_hud_draw(&hud);
	draw_hud_part(&hud, &draw, tex);
	mlx_put_image_to_window(disp->mlx_ptr, disp->win_ptr, hud.ptr, b.x, b.y);

	return (0);
}
