#include "cub3d.h"

int	hud_get_item(t_disp *disp, t_player *player)
{
	t_vecd	scale;
	t_veci	bias;

	bias.y = (double)disp->h / 2;
	bias.x = (double)disp->w / 2;
	scale.y = DISP2HUD_ITEM_H;
	scale.x = DISP2HUD_ITEM_W;
	player->clk[TIC_ITEM].end = clock();
	if (player->clk[TIC_ITEM].end - player->clk[TIC_ITEM].beg <= 1000000)
		draw_hud(disp, disp->tex[CONFIG_LUP], scale, bias);
	return (0);
}

int	hud_get_attack(t_disp *disp, t_player *player)
{
	t_vecd	scale;
	t_veci	bias;

	bias.y = (double)disp->h / 2;
	bias.x = (double)disp->w / 2;
	scale.y = DISP2HUD_ITEM_H;
	scale.x = DISP2HUD_ITEM_W;
	player->clk[TIC_ATTACK].end = clock();
	if (player->clk[TIC_ATTACK].end - player->clk[TIC_ATTACK].beg <= 1000000)
		draw_hud(disp, disp->tex[CONFIG_LDW], scale, bias);
	return (0);
}

int	hud_life_bar(t_disp *disp, t_player *player)
{
	t_vecd	scale;
	t_veci	bias;

	bias.y = (double)disp->h / 8;
	bias.x = (double)disp->w * 6 / 8;
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
	ret |= hud_get_item(disp, player);
	ret |= hud_get_attack(disp, player);
	ret |= hud_life_bar(disp, player);
	return (ret);
}
