/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 07:05:15 by yekim             #+#    #+#             */
/*   Updated: 2020/12/09 17:22:34 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

# include "../mlx.h"
# include <math.h>
# include <string.h>//
# include <unistd.h>
# include <stdio.h> //
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>

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
# define KEY_O 31
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
# define MAP_ITEM '3'
# define MAP_ITEM_VAL 3
# define MAP_SECRET '4'
# define MAP_SECRET_VAL 4
# define MAP_OPDOOR '5'
# define MAP_OPDOOR_VAL 5
# define MAP_CLDOOR '6'
# define MAP_CLDOOR_VAL 6


/*
** degree and radian
*/
# define DEG2RAD M_PI / 180
# define RAD2DEG 180 / M_PI
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
# define TEXTURE_NUMBER 10

/*
** bonus
*/
# define CONFIG_ITEM 5
# define TEXTURE_ITEM_FILE "./textures/red.xpm"
# define CONFIG_SECRET 6
# define TEXTURE_SECRET_FILE "./textures/question2.xpm"
# define CONFIG_OPDOOR 7
# define TEXTURE_OPDOOR_FILE "./textures/question2.xpm"
# define CONFIG_CLDOOR 8
# define TEXTURE_CLDOOR_FILE "./textures/question2.xpm"
# define CONFIG_HUD 9
# define TEXTURE_HUD_FILE "./textures/logo.xpm"

/*
** calc_basic
*/
# define EPSILON 0.00001

/*
** player speed setting
*/
# define ROT_SPEED 1.5 * DEG2RAD
# define TRANS_SPEED 0.03

/*
** hit side
*/
# define HIT_SIDE_X 0
# define HIT_SIDE_Y 1

/*
** item scale
*/
# define SPRITE_VDIV 1.0
# define SPRITE_UDIV 1.0
# define SPRITE_MOVE 100.0
# define ITEM_VDIV 1.5
# define ITEM_UDIV 1.5
# define ITEM_MOVE 100.0
# define ITEM_APPROACH_DIST 1.0

/*
** skybox
*/
# define DISP2SKYW 3 / 7
# define DISP2SKYH 2 / 7

/*
** skybox
*/
# define DISP2HUDW 1 / 7
# define DISP2HUDH 1 / 7

/*
** color set
*/
# define COLOR_SKY_BACKBACKGROUND 0xFF000000
# define COLOR_SKY_BACKGROUND 0x5F000000
# define COLOR_SKY_WALL 1644825 
# define COLOR_SKY_ROAD 13158600 
# define COLOR_SKY_ITEM 15080990
# define COLOR_SKY_SECRET 14329120
# define COLOR_SKY_SPRITE 52224
# define COLOR_SKY_PLAYER 0xFF8C8C
# define COLOR_SKY_DIR 0x32708D
# define COLOR_SKY_RAY_DIR 0x0FFFDB1
# define SIZE_SKY_RAY 1
# define SIZE_SKY_PLAYER 5


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

typedef struct		s_spr
{
	t_vecd			pos;
	int				tex_nbr;
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
	int				pos_flag;
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

typedef struct		s_tex
{
	void			*ptr;
	int				*data;
	int				w;
	int				h;
}					t_tex;

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
	int				key_w;
	int				key_s;
	int				key_a;
	int				key_d;
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

/*
** FUNCTIONS ======================================
*/

/*
** run cub3d program
*/
int					cub3d_run(t_disp *disp);

/*
** parse configuration
*/
int					parse_config(t_disp *disp, char **line_buf, int *k);

/*
** parse map
*/
int					parse_map(t_disp *disp, char **map, int map_beg);
int					init_bonus_info(t_disp *disp);
int					bonus_config(t_disp *disp);
/*
** player motion
*/
void				start_orient(t_player *player, char orient);
void				move_forward(t_player *player, t_map map);
void				move_backward(t_player *player, t_map map);
void				turn_left(t_player *player);
void				turn_right(t_player *player);
void				set_zaxis_motion(t_disp *disp, t_player *player);

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
double				dda_algorithm(t_player *player, t_hit *hit_point, t_map map);

/*
** display drawing untex line
*/
void				draw_untex_wall(t_disp disp, int x, const t_hit hit_point);

/*
** display drawing tex line
*/
int					draw_tex_wall(t_disp *disp, t_player *player, int x, t_hit hit_point);

/*
** display drawing tex line
*/
int					draw_tex_background(t_disp *disp, t_player player);

/*
** display drawing sprite shape
*/
int					draw_sprite(t_disp *disp, t_player *p, double *perp_buf);
void				sort_spr_pair(t_pair *spr_pair, int spr_cnt);
void				get_close_sprite(t_disp *disp, t_player *p);
t_vecd				set_sprite_scale(t_draw *draw, t_vecd coef, int tex_nbr);

/*
** display skybox
*/
int					draw_skybox(t_disp *disp, t_player *player);

/*
** display hud
*/
int					draw_hud(t_disp *disp, t_player *player);

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

#endif
