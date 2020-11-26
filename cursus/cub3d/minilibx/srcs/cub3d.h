/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 07:05:15 by yekim             #+#    #+#             */
/*   Updated: 2020/11/26 17:47:15 by yekim            ###   ########.fr       */
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
# define ERR_MALLOC 1
# define ERR_PARSE 1
# define ERR_MESSAGE "ERROR ERROR ERROR\n"

/*
** file setting
*/
# define FILE_EXTENSION ".cub"
# define FILE_DATA 4096

/*
** keyboard codes
*/
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_ESC 53

# define MAP_WIDTH 24
# define MAP_HEIGHT 24
//# define SCREEN_WIDTH 640
//# define SCREEN_HEIGHT 480

# define X_EVENT_KEY_PRESS   2
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
** degree and radian
*/
# define DEG2RAD M_PI / 180
# define RAD2DEG 180 / M_PI
# define ROT_SPEED 15 * DEG2RAD
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'
# define START_NORTH_ANGLE 270 
# define START_SOUTH_ANGLE 90
# define START_WEST_ANGLE 0
# define START_EAST_ANGLE 180

/*
** color code
*/
# define COLOR_CEIL 0x0099CCFF
# define COLOR_FLOOR 0x00CC9900

/*
** texture setting
*/
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define TEXTURE_NUMBER 11
# define TEXTURE_TOTALSIZE 4096

/*
** get next line
*/
# define BUFFER_SIZE 1024

/*
** calc_basic
*/
# define EPSILON 0.00001

/*
** sprite setting
*/
# define SPRITE_NUMBER 19

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

typedef struct		s_spr
{
	t_vecd			pos;
	int				tex_nbr;
}					t_spr;

typedef struct		s_pair
{
	int				order;
	double			dist;
}					t_pair;

typedef struct		s_img
{
	void			*ptr;
	int				*data;
	int				width;
	int				height;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_tex
{
	void			*ptr;
	int				*data;
	int				width;
	int				height;
}					t_tex;

typedef struct		s_disp
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
	t_img			img;
	t_tex			tex[TEXTURE_NUMBER];
	int				config;
	int				floor_color;
	int				ceil_color;
}					t_disp;	

typedef struct		s_player
{
	t_vecd			pos;
	t_vecd			dir;
	t_vecd			plane;
	double			trans_speed;
	double			rot_speed;
	t_vecd			ray_dir;
	t_vecd			sray_dist;
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
	int				hit;
}					t_dda;

typedef struct		s_hit
{
	t_veci			pos;
	int				side;
	int				color;
	double			perp_wall_dist;
}					t_hit;

typedef struct		s_draw
{
	int				y;
	int				x;
	int				beg;
	int				end;
	int				ty;
	int				tx;
	int				line_height;
	int				xbeg;
	int				xend;
	int				xctr;
}					t_draw;

/*
** FUNCTIONS ======================================
*/

/*
** parse configuration
*/
int					parse_config(t_disp *disp, char **line_buf);

/*
** player motion
*/
void				start_orient(t_player *player, char orient);
void				move_forward(t_player *player);
void				move_backward(t_player *player);
void				turn_left(t_player *player);
void				turn_right(t_player *player);

/*
** calculate basic algorithm
*/
double				calc_dist(t_vecd p1, t_vecd p2);
double				calc_det(t_vecd v1, t_vecd v2);

/*
** calculate vector operation
*/
t_vecd				translate_vec(t_vecd pos, t_vecd dir, double trans);
t_vecd				rotate_vec(t_vecd dir, double theta);

/*
** calculate dda algorithm
*/
double				dda_algorithm(const t_player *player, t_hit *hit_point);

/*
** display drawing untex line
*/
void				draw_untex_wall(t_disp disp, int x, const t_hit hit_point);
void				clear_draw(int *data);

/*
** display drawing tex line
*/
int					draw_tex_wall(t_disp disp, t_player player, int x, t_hit hit_point);

/*
** display drawing sprite shape
*/
int					draw_sprite(t_disp disp, t_player player, t_hit hit_point, double *z_buf);

/*
** load images from xpm files
*/
int					load_tex(t_tex *tex, char *file_name);
int					load_tex_group(t_disp *disp);

/*
** get nextline 
*/
int					get_next_line(int fd, char **line);

/*
** ft_split
*/
char				**ft_split(char const *s, char c);
void				free_split_arr(char **tab);

/*
** utilities for string
*/
size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strdup(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_atoi(char *nptr);
int					check_is_number_arr(char **nbr_arr);
/*
** keyboard hook from user
*/
int					key_press(int key, t_player *player);

#endif
