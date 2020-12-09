#include "cub3d.h"

t_img	set_hud_img(t_disp *disp)
{
	t_img	ret;
	int		tmp;

	ret.w =	(int)disp->w * DISP2HUDW;
	ret.h =	(int)disp->h * DISP2HUDH;
	ret.ptr = mlx_new_image(disp->mlx_ptr, ret.w, ret.h);
	ret.data = (int *)mlx_get_data_addr(ret.ptr, &tmp, &tmp, &tmp);

	t_draw	draw;
	t_tex	tex;
	t_vecd	tpos;
	t_vecd	step;

	tex = disp->tex[CONFIG_HUD];
	draw.xctr = (int)((double)ret.w / 2);
	draw.yctr = (int)((double)ret.h / 2);

	step.x = (double)tex.w / ret.w;
	step.y = (double)tex.h / ret.h;
			
	draw.lh = ret.h;
	draw.xbeg = (int)fmax(draw.xctr - (double)ret.w / 2, 0);
	draw.xend = (int)fmin(draw.xctr + (double)ret.w / 2, ret.w - 1);
	draw.ybeg = (int)fmax(draw.yctr - (double)ret.h / 2, 0);
	draw.yend = (int)fmin(draw.yctr + (double)ret.h / 2, ret.h - 1);

	draw.x = -1;
	while (++draw.x < ret.w)
	{
		draw.y = -1;
		while (++draw.y < ret.h)
			ret.data[draw.y * ret.w + draw.x] = 0xFF000000;
	}
	
	draw.x = draw.xbeg - 1;
	while (++(draw.x) < draw.xend)
	{
		tpos.x = draw.x - draw.xctr + (double)ret.w / 2;
		draw.tx = (int)fmin(tpos.x * step.x, tex.w - 1);	
		draw.y = draw.ybeg - 1;
		while (++(draw.y) < draw.yend)
		{
			tpos.y = draw.y - draw.yctr + (double)ret.h / 2;
			draw.ty = (int)fmin(tpos.y * step.y, tex.h - 1);
			draw.color = tex.data[draw.ty * tex.w + draw.tx];	
			ret.data[draw.y * ret.w + draw.x] = draw.color;
		}
	}
	return (ret);
}

int	draw_hud(t_disp *disp, t_player *player)
{
	t_img	hud;
	t_veci	bias;

	(void)player;
	hud = set_hud_img(disp);
	bias.x = (double)disp->w / 2 + (double)hud.w / 2;
	bias.y = (double)disp->h / 2 + (double)hud.h / 2;
	mlx_put_image_to_window(disp->mlx_ptr, disp->win_ptr, hud.ptr, bias.x, bias.y);

	return (0);
}

