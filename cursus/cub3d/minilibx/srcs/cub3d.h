/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 07:05:15 by yekim             #+#    #+#             */
/*   Updated: 2020/11/21 00:12:36 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

# include "../mlx.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

/*
** PRECOMPILING ======================================
** keyboard codes
*/
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_ESC 53

# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

# define X_EVENT_KEY_PRESS   2
# define X_EVENT_KEY_EXIT    17

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
# define TEXTURE_NUMBER 8
# define TEXTURE_TOTALSIZE 4096

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

typedef struct		s_texture
{
	void			*ptr;
	int				*data;
	int				width;
	int				height;
}					t_texture;

typedef struct		s_disp
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	t_texture		texture[TEXTURE_NUMBER];
}					t_disp;	

typedef struct		s_player
{
	t_vecd			pos;
	t_vecd			dir;
	t_vecd			plane;
	double			trans_speed;
	double			rot_speed;
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


/*
** FUNCTIONS ======================================
** player motion
*/
void				move_forward(t_player *player);
void				move_backward(t_player *player);
void				turn_left(t_player *player);
void				turn_right(t_player *player);

/*
** calculate basic algorithm
*/
int					calc_max(int nbr1, int nbr2);
int					calc_min(int nbr1, int nbr2);

/*
** calculate vector operation
*/
t_vecd				translate_vec(t_vecd pos, t_vecd dir, double trans);
t_vecd				rotate_vec(t_vecd dir, double theta);

/*
** calculate dda algorithm
*/
double				dda_algorithm(const t_player *player, const t_vecd ray_dir, t_veci *hit_point, int *side);

/*
** display drawing
*/
void				draw_line(int *data, int x, double perp_wall_dist, int color);
void				clear_draw(int *data);
#endif
