#include "cub3d.h"

int	hud_get_item(t_disp *disp, t_player *player)
{
	t_vecd	scale;
	t_veci	bias;

	bias.y = (double)disp->h / 2;
	bias.x = (double)disp->w / 2;
	time(&player->tic.end);	
	scale.y = DISP2HUD_ITEM_H;
	scale.x = DISP2HUD_ITEM_W;
	if (difftime(player->tic.end, player->tic.beg) <= 0.5)
		draw_hud(disp, disp->tex[CONFIG_UP], scale, bias);
	return (0);
}

int	draw_hud_series(t_disp *disp, t_player *player)
{
	int		ret;

	ret = 0;
	ret |= hud_get_item(disp, player);
	return (ret);
}
