#include "cub3d.h"

int	hud_get_item(t_disp *disp, t_player *player)
{
	t_vecd	scale;
	t_veci	bias;

	bias.y = (double)disp->h / 2;
	bias.x = (double)disp->w / 2;
	time(&player->tic[TIC_LIFE].end);	
	scale.y = DISP2HUD_ITEM_H;
	scale.x = DISP2HUD_ITEM_W;
#if 0
	if (difftime(player->tic[TIC_LIFE].end, player->tic[TIC_LIFE].beg) <= 1)
		draw_hud(disp, disp->tex[CONFIG_UP], scale, bias);
#endif
	player->clk[TIC_LIFE].end = clock();
	if (player->clk[TIC_LIFE].end - player->clk[TIC_LIFE].beg <= 1000000)
	{
		draw_hud(disp, disp->tex[CONFIG_UP], scale, bias);
		player->clk[TIC_LIFE].beg = player->clk[TIC_LIFE].end;
	}
	return (0);
}

int	hud_life_bar(t_disp *disp, t_player *player)
{
	t_vecd	scale;
	t_veci	bias;

	bias.y = (double)disp->h / 8;
	bias.x = (double)disp->w * 6 / 8;
	time(&player->tic[TIC_LIFE].end);	
	scale.y = DISP2HUD_LIFE_H;
	scale.x = DISP2HUD_LIFE_W;
	player->life = (int)fmin(player->life, MAX_LIFE);
	player->life = (int)fmax(player->life, MIN_LIFE);
	draw_hud(disp, disp->tex[(int)(CONFIG_L0 + player->life)], scale, bias);
	return (0);
}

int	draw_hud_series(t_disp *disp, t_player *player)
{
	int		ret;

	ret = 0;
	//ret |= hud_get_item(disp, player);
	ret |= hud_life_bar(disp, player);
	return (ret);
}
