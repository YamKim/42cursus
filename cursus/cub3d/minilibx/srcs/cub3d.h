/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 07:05:15 by yekim             #+#    #+#             */
/*   Updated: 2020/12/22 18:56:00 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

# include "../mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <time.h>
# include <stdio.h>

/*
** PRECOMPILING ======================================
*/

/*
** error code
*/
# define ERR_TEXTURE_CALL 1
# define ERR_RUN 1
# define ERR_FILE 1
# define ERR_READ 1
# define ERR_MALLOC -1
# define ERR_PARSE 1
# define ERR_PARSE_CONFIG 3
# define ERR_PARSE_MAP 4
# define ERR_DRAW_IMG 1
# define ERR_BONUS_CONFIG 5
# define ERR_MESSAGE "ERROR ERROR ERROR\n"

/*
** file setting
*/
# define FILE_EXTENSION ".cub"
# define FILE_EXTENSION_LENGTH 4
# define FILE_DATA 4096

/*
** keyboard codes
*/
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_J 31
# define KEY_H 4
# define KEY_G 5

# define KEY_ESC 53

# define X_EVENT_KEY_PRESS   2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT    17

/*
** configuration
*/
# define CONFIG_NUMBER 8
# define CONFIG_NO 0
# define CONFIG_SO 1
# define CONFIG_WE 2
# define CONFIG_EA 3
# define CONFIG_S 4
# define CONFIG_R 5
# define CONFIG_F 6
# define CONFIG_C 7

/*
** bonus
*/
# define TEXTURE_SECRET 5
# define TEXTURE_SECRET_FILE "./textures/eagle.xpm"
# define TEXTURE_CLDOOR 6
# define TEXTURE_CLDOOR_FILE "./textures/question.xpm"
# define TEXTURE_OPDOOR 7
# define TEXTURE_OPDOOR_FILE "./textures/question2.xpm"
# define TEXTURE_ITEM 8
# define TEXTURE_ITEM_FILE "./textures/red.xpm"
# define TEXTURE_ATTACK 9
# define TEXTURE_ATTACK_FILE "./textures/attack/A0.xpm"

# define CONFIG_L0 10
# define TEXTURE_L0_FILE "./textures/life/life0.xpm"
# define CONFIG_L1 11
# define TEXTURE_L1_FILE "./textures/life/life1.xpm"
# define CONFIG_L2 12
# define TEXTURE_L2_FILE "./textures/life/life2.xpm"
# define CONFIG_L3 13
# define TEXTURE_L3_FILE "./textures/life/life3.xpm"
# define CONFIG_L4 14
# define TEXTURE_L4_FILE "./textures/life/life4.xpm"
# define CONFIG_L5 15
# define TEXTURE_L5_FILE "./textures/life/life5.xpm"
# define CONFIG_LUP 16
# define TEXTURE_LUP_FILE "./textures/up.xpm"
# define CONFIG_LDW 17
# define TEXTURE_LDW_FILE "./textures/down.xpm"

/*
** animation
*/
# define MAX_ANI_IDX 4
# define MIN_ANI_IDX 0
# define CONFIG_A0 0
# define TEXTURE_A0_FILE "./textures/attack/A0.xpm"
# define CONFIG_A1 1
# define TEXTURE_A1_FILE "./textures/attack/A1.xpm"
# define CONFIG_A2 2
# define TEXTURE_A2_FILE "./textures/attack/A2.xpm"
# define CONFIG_A3 3
# define TEXTURE_A3_FILE "./textures/attack/A3.xpm"
# define CONFIG_A4 4
# define TEXTURE_A4_FILE "./textures/attack/A4.xpm"

/*
** limit maximum number
*/
# define MAX_NUM_SPRITE 100
# define MAX_NUM_MAP_WIDTH 100
# define MAX_NUM_MAP_HEIGHT 100

/*
** map
*/
# define MAP_ROAD '0'
# define MAP_ROAD_VAL 0
# define MAP_WALL '1'
# define MAP_WALL_VAL 1
# define MAP_SPRITE '2'
# define MAP_SPRITE_VAL 2
# define MAP_SPACE ' '
# define MAP_SPACE_VAL -1
# define MAP_BOARDER_VAL -2
# define MAP_EXCEPTION_VAL -3
# define MAP_UNUSED_VAL -4

/*
** bonus
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
** degree and radian
*/
# define DEG2RAD 0.017453
# define RAD2DEG 57.29578
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'
# define START_NORTH_ANGLE 0
# define START_SOUTH_ANGLE 180
# define START_WEST_ANGLE 90
# define START_EAST_ANGLE -90

# define PLAYER_JUMP 80
# define PLAYER_CROUCH -80

/*
** texture setting
*/
# define TEXTURE_NUMBER 20
# define TEXTURE_ANI_NUMBER 5

/*
** texture setting
*/
# define TIC_NUMBER 3
# define TIC_ITEM 0
# define TIC_ATTACK 1

/*
** calc_basic
*/
# define EPSILON 0.00001

/*
** player speed setting
** ROT_SPEED = 2.0 * DEG2RAD
*/
# define ROT_SPEED 0.034906
# define TRANS_SPEED 0.04

/*
** hit side
*/
# define HIT_SIDE_X 0
# define HIT_SIDE_Y 1

/*
** item scale
*/
# define SCALE_HDIV_SPRITE 1.0
# define SCALE_WDIV_SPRITE 1.0
# define SCALE_MOVE_SPRITE 200
# define SCALE_HDIV_ITEM 0.6
# define SCALE_WDIV_ITEM 0.6
# define SCALE_MOVE_ITEM 300
# define SCALE_HDIV_ATTACK 1.0
# define SCALE_WDIV_ATTACK 1.0
# define SCALE_MOVE_ATTACK 200
# define APPROACH_ITEM_DIST 1.0
# define APPROACH_ATTACK_DIST 0.4

/*
** skybox
** DISP2SKYW: 3 / 7
** DISP2SKYH: 2 / 7
*/
# define DISP2SKYW 0.4285714286
# define DISP2SKYH 0.2857142857

/*
** hud
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
** color set
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
# define COLOR_SKY_PLAYER 0xFF8C8C
# define COLOR_SKY_DIR 0x32708D
# define COLOR_SKY_RAY_DIR 0x0FFFDB1
# define SIZE_SKY_RAY 1
# define SIZE_SKY_PLAYER 5

/*
** life bar
*/
# define ATTACK_PUSH_BACK 20
# define LIFE_DEFAULT 1

/*
** structures
*/
typedef struct		s_vecd
{
	double			x;
	double			y;
}					t_vecd;

typedef struct		s_veci
{
	int				x;
	int				y;
}					t_veci;

typedef struct		s_pair
{
	int				ord;
	double			dist;
}					t_pair;

typedef struct		s_tex
{
	void			*ptr;
	int				*data;
	int				w;
	int				h;
}					t_tex;

typedef struct		s_ani
{
	int				upflag;
	int				idx;
	t_tex			tex[TEXTURE_ANI_NUMBER];
}					t_ani;

typedef struct		s_tic
{
	time_t			beg;
	time_t			end;
}					t_tic;

typedef struct		s_clk
{
	clock_t			beg;
	clock_t			end;
}					t_clk;

typedef struct		s_spr
{
	t_vecd			pos;
	int				tex_nbr;
	t_tic			tic;
	t_clk			clk;
	t_tex			*tex;
	t_ani			ani;
}					t_spr;

typedef struct		s_lst
{
	t_spr			spr;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_map
{
	int				max_w;
	int				h;
	int				data[MAX_NUM_MAP_WIDTH][MAX_NUM_MAP_HEIGHT];
}					t_map;

typedef struct		s_img
{
	void			*ptr;
	int				*data;
	int				w;
	int				h;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_disp
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				w;
	int				h;
	int				hctr_bias;
	int				config;
	int				floor_color;
	int				ceil_color;
	t_img			img;
	t_tex			tex[TEXTURE_NUMBER];
	t_tex			ani_tex[TEXTURE_ANI_NUMBER];
	t_clk			clk[TEXTURE_NUMBER];
	t_map			map;
	t_vecd			start_pos;
	char			start_orient;
	int				spr_cnt;
	t_lst			*spr_lst;
}					t_disp;

typedef struct		s_player
{
	t_vecd			pos;
	t_vecd			dir;
	t_vecd			plane;
	double			trans_speed;
	double			rot_speed;
	t_vecd			ray_dir;
	t_vecd			coef;
	int				key;
	int				life;
	t_tic			tic[TIC_NUMBER];
	t_clk			clk[TIC_NUMBER];
}					t_player;

typedef struct		s_loop
{
	t_disp			*disp;
	t_player		*player;
}					t_loop;

typedef struct		s_dda
{
	t_vecd			ray_dir;
	t_vecd			side_dist;
	t_vecd			delta_dist;
	t_veci			step;
}					t_dda;

typedef struct		s_hit
{
	t_veci			pos;
	int				side;
	double			perp_wall_dist;
	int				door_type;
	int				secret_door;
}					t_hit;

typedef struct		s_draw
{
	int				y;
	int				x;
	int				ybeg;
	int				yend;
	int				ty;
	int				tx;
	int				lh;
	int				xbeg;
	int				xend;
	int				xctr;
	int				yctr;
	int				bias;
	int				color;
}					t_draw;

typedef struct		s_bmp
{
	char			id[2];
	int				file_size;
	int				unused;
	int				offset;
	int				dib;
	int				width;
	int				height;
	char			plane[2];
	char			bpp[2];
	int				compression;
	int				raw_bitmap_size;
	int				resx;
	int				resy;
	int				number_of_colors;
	int				important_colors;
}					t_bmp;

/*
** FUNCTIONS ======================================
*/

/*
** initialize disp and player
*/
void				init_disp_setting(t_disp *disp);
void				init_player_setting(t_disp *disp, t_player *player);
/*
** run cub3d program
*/
int					cub3d_run(t_disp *disp, t_player *player, int capture_flag);

/*
** run cub3d program
*/
void				finish_program(t_loop *lv);

/*
** parse configuration
*/
int					parse_config(t_disp *disp, char **line_buf, int *k);
int					get_bonus_texture(t_disp *disp);

/*
** parse map
*/
int					parse_map(t_disp *disp, char **map, int map_beg);
int					set_animation(t_disp *disp, t_spr *spr, char data);

/*
** player motion
*/
void				start_orient(t_player *player, char orient);
void				move_forward(t_player *player, t_map map);
void				move_backward(t_player *player, t_map map);
void				turn_left(t_player *player);
void				turn_right(t_player *player);
void				set_zaxis_motion(t_disp *disp, t_player *player);
void				open_door_trigger(t_disp *disp, t_player *player);

/*
** operate vector calculation
*/
t_vecd				translate_vec(t_vecd pos, t_vecd dir, double trans);
t_vecd				rotate_vec(t_vecd dir, double theta);

/*
** calculate basic algorithm
*/
double				calc_dist(t_vecd p1, t_vecd p2);
double				calc_det(t_vecd v1, t_vecd v2);
/*
** calculate dda algorithm
*/
double				dda_algorithm(t_player *player, t_hit *hp, t_map map);

/*
** display drawing untex line
*/
void				draw_untex_wall(t_disp disp, int x, const t_hit hit_point);

/*
** display drawing tex line
*/
int					draw_tex_wall(t_disp *disp, t_player *p, int x, t_hit *hp);

/*
** display drawing tex line
*/
int					draw_tex_background(t_disp *disp, t_player *player);

/*
** display drawing sprite shape
*/
int					draw_sprite(t_disp *disp, t_player *p, double *perp_buf);
void				sort_spr_pair(t_pair *spr_pair, int spr_cnt);
t_vecd				set_sprite_scale(t_draw *draw, t_vecd coef, int tex_nbr);
void				get_close_sprite(t_disp *disp, t_player *p);
void				animate_sprite(t_spr *spr);
int					check_order(t_disp *dp, t_player *p, t_draw *dr, double *b);

/*
** display skybox
*/
int					draw_skybox(t_disp *disp, t_player *player);

/*
** display hud
*/
int					draw_hud(t_disp *dp, t_tex tex, t_vecd scale, t_veci bias);
int					draw_hud_series(t_disp *disp, t_player *player);

/*
** load images from xpm files
*/
int					check_file(char *fname);
int					open_file(char *fname);
int					load_tex(t_tex *tex, char *file_name);

/*
** ft_split
*/
char				**ft_split(char const *s, char c, int *wc);
void				free_split_arr(char **tab);

/*
** ft_atoi
*/
int					ft_atoi(char *nptr);

/*
** utilities for string
*/
size_t				ft_strlen(const char *str);
void				*ft_memset(void *s, int c, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strdup(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);

/*
** keyboard hook from user
*/
int					key_press(int key, t_loop *lv);
int					key_release(int key, t_loop *lv);
void				key_update(t_loop *lv);

/*
** check validity
*/
int					is_number_arr(char **arr, int index_num, int type);
int					is_map_valid(t_map map);
int					is_secret(int map_data, t_hit *hit_point, int *hit_flag);

/*
** show data
*/
void				show_map_data(t_disp disp);
void				show_lst_data(t_lst *itr);

/*
** list setting
*/
t_lst				*lst_new_spr(t_spr spr);
void				lst_add_back(t_lst **lst, t_lst *new_lst);
t_lst				*lst_get_idx(t_lst *lst, int idx);
void				lst_del_idx(t_lst **lst, int idx);
void				lst_clear(t_lst **lst);

/*
** bonus setting
*/
/*
** door
*/
int					check_door_type(t_hit *hit_point, int map_data);

int					main_loop(t_loop *lv);
int					save_bmp_image(t_loop lv, t_disp *disp);

#endif
