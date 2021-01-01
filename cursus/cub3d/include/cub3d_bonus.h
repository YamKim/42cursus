/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:58:21 by yekim             #+#    #+#             */
/*   Updated: 2021/01/01 12:17:01 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_BONUS_H
# define _CUB3D_BONUS_H

# include "./utils.h"

# define ERR_BONUS_CONFIG 5

/*
** PLAYER ACTION
*/
# define PLAYER_UP 80
# define PLAYER_DOWN -80

/*
** KEBOARD INPUT
*/
# define KEY_H 4
# define KEY_G 5
# define MOVE_H 6
# define MOVE_G 7

/*
** MOUSE HOOK
*/
# define EVENT_MOUSE_PRESS 4
# define EVENT_MOUSE_RELEASE 5
# define EVENT_MOUSE_MOVE 6

/*
** MAP VALUE SETTING
*/
# define MAP_SECRET '3'
# define MAP_SECRET_VAL 3
# define MAP_CLDOOR '4'
# define MAP_CLDOOR_VAL 4
# define MAP_OPDOOR '5'
# define MAP_OPDOOR_VAL 5
# define MAP_ITEM '6'
# define MAP_ITEM_VAL 6
# define MAP_ATTACK '7'
# define MAP_ATTACK_VAL 7

/*
** SECRET/OPEN/CLOSE DOOR, SPRITE TEXTURE
*/
# define TEXTURE_SECRET 5
# define TEXTURE_SECRET_FILE "./textures/door/brown_bricks.xpm"
# define TEXTURE_CLDOOR 6
# define TEXTURE_CLDOOR_FILE "./textures/door/question.xpm"
# define TEXTURE_OPDOOR 7
# define TEXTURE_OPDOOR_FILE "./textures/door/question2.xpm"
# define TEXTURE_ITEM 8
# define TEXTURE_ITEM_FILE "./textures/item/red.xpm"
# define TEXTURE_ATTACK 9
# define TEXTURE_ATTACK_FILE "./textures/attack/A0.xpm"

/*
** HUD TEXTURE
*/
# define TEXTURE_L0 10
# define TEXTURE_L0_FILE "./textures/life/L0.xpm"
# define TEXTURE_L1 11
# define TEXTURE_L1_FILE "./textures/life/L1.xpm"
# define TEXTURE_L2 12
# define TEXTURE_L2_FILE "./textures/life/L2.xpm"
# define TEXTURE_L3 13
# define TEXTURE_L3_FILE "./textures/life/L3.xpm"
# define TEXTURE_L4 14
# define TEXTURE_L4_FILE "./textures/life/L4.xpm"
# define TEXTURE_L5 15
# define TEXTURE_L5_FILE "./textures/life/L5.xpm"
# define TEXTURE_LUP 16
# define TEXTURE_LUP_FILE "./textures/life/up.xpm"
# define TEXTURE_LDW 17
# define TEXTURE_LDW_FILE "./textures/life/down.xpm"

/*
** BACKGROUND TEXTURE
*/
# define TEXTURE_CEIL 20
# define TEXTURE_CEIL_FILE "./textures/bg/background.xpm"
# define TEXTURE_FLOOR 21
# define TEXTURE_FLOOR_FILE "./textures/bg/grass.xpm"

/*
** ANIMATION TEXTURE
*/
# define MAX_ANI_IDX 4
# define MIN_ANI_IDX 0
# define TEXTURE_A0 0
# define TEXTURE_A0_FILE "./textures/attack/A0.xpm"
# define TEXTURE_A1 1
# define TEXTURE_A1_FILE "./textures/attack/A1.xpm"
# define TEXTURE_A2 2
# define TEXTURE_A2_FILE "./textures/attack/A2.xpm"
# define TEXTURE_A3 3
# define TEXTURE_A3_FILE "./textures/attack/A3.xpm"
# define TEXTURE_A4 4
# define TEXTURE_A4_FILE "./textures/attack/A4.xpm"

/*
** SPRITE SCALE
*/
# define SCALE_HDIV_ITEM 0.6
# define SCALE_WDIV_ITEM 0.6
# define SCALE_MOVE_ITEM 300
# define SCALE_HDIV_ATTACK 1.0
# define SCALE_WDIV_ATTACK 1.0
# define SCALE_MOVE_ATTACK 200
# define APPROACH_ITEM_DIST 1.0
# define APPROACH_ATTACK_DIST 0.4

/*
** SKYBOX SCALE
** DISP2SKYW: 3 / 7
** DISP2SKYH: 2 / 7
*/
# define DISP2SKYW 0.4285714286
# define DISP2SKYH 0.2857142857

/*
** HUD SETTING / SCALE
** DISP2HUD_ITEM_W: 3 / 7
** DISP2HUD_ITEM_H: 3 / 7
** DISP2HUD_LIFE_W: 1 / 6
** DISP2HUD_LIFE_H: 1 / 12
*/
# define MAX_LIFE 5
# define MIN_LIFE 0
# define DISP2HUD_ITEM_W 0.4285714286
# define DISP2HUD_ITEM_H 0.4285714286
# define DISP2HUD_LIFE_W 0.1666666667
# define DISP2HUD_LIFE_H 0.0833333333

/*
** LIFE BAR SETTING
*/
# define ATTACK_PUSH_BACK 20
# define LIFE_DEFAULT 1

/*
** SKYBOX COLORCODE
*/
# define COLOR_SKY_BACKBACKGROUND 0xFF000000
# define COLOR_SKY_BACKGROUND 0x5F000000
# define COLOR_SKY_WALL 1644825
# define COLOR_SKY_ROAD 13158600
# define COLOR_SKY_SPRITE 0x0AA344
# define COLOR_SKY_ITEM 0xF47983
# define COLOR_SKY_ATTACK 0xF20C00
# define COLOR_SKY_SECRET 1644825
# define COLOR_SKY_OPCLDOOR 0xFFF143
# define COLOR_SKY_PLAYER 0x000000
# define COLOR_SKY_DIR 0x32708D
# define COLOR_SKY_RAY_DIR 0x0FFFDB1
# define SIZE_SKY_RAY 1
# define SIZE_SKY_PLAYER 1

/*
** TIME SETTING
*/
# define TIC_ITEM 0
# define TIC_ATTACK 1

typedef struct		s_bg
{
	t_vecd			ray_dir0;
	t_vecd			ray_dir1;
	double			row_dist;
	t_vecd			step;
	t_draw			draw;
}					t_bg;

/*
** BONUS TEXTURE
*/
int					get_bonus_texture(t_disp *disp);

/*
** BONUS SETTING
*/
void				init_setting_bonus(t_disp *disp);

/*
** PLAYER ACTION
*/
void				set_zaxis_motion(
					t_disp *disp,
					t_player *player);

void				open_door_trigger(
					t_disp *disp,
					t_player *player);

/*
** SPRITE APPROACH
*/
void				get_close_sprite(
					t_disp *disp,
					t_player *p);

/*
** DRAWING SKYBOX
*/
int					draw_skybox(
					t_disp *disp,
					t_player *player);

/*
** DRAWING HUD
*/
int					draw_hud(
					t_disp *disp,
					t_tex *tex,
					int hud_nbr,
					t_veci bias);

int					draw_hud_series(
					t_disp *disp,
					t_player *player);

/*
** DRAWING ANIMATED SPRITE
*/
int					set_animation(
					t_disp *disp,
					t_spr *spr,
					char data);

#endif
