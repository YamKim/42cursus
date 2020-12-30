/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:32:21 by yekim             #+#    #+#             */
/*   Updated: 2020/12/31 08:52:44 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTILS_H
# define _UTILS_H

# include <time.h>

/*
** ARRAY SIZE SETTING
*/
# define MAX_NUM_MAP_WIDTH 100
# define MAX_NUM_MAP_HEIGHT 100
# define TEXTURE_NUMBER 30
# define TIC_NUMBER 3
# define TEXTURE_ANI_NUMBER 5

typedef struct		s_tex
{
	void			*ptr;
	int				*data;
	int				w;
	int				h;
}					t_tex;

typedef struct		s_veci
{
	int				x;
	int				y;
}					t_veci;

typedef struct		s_vecd
{
	double			x;
	double			y;
}					t_vecd;

typedef struct		s_ani
{
	int				upflag;
	int				idx;
	t_tex			tex[TEXTURE_ANI_NUMBER];
}					t_ani;

typedef struct		s_clk
{
	clock_t			beg;
	clock_t			end;
}					t_clk;

typedef struct		s_spr
{
	t_vecd			pos;
	int				tex_nbr;
	t_clk			clk;
	t_tex			*tex;
	t_ani			ani;
}					t_spr;

typedef struct		s_lst
{
	t_spr			spr;
	struct s_lst	*next;
}					t_lst;

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
** structures
*/
typedef struct		s_pair
{
	int				ord;
	double			dist;
}					t_pair;

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
	int				mouse;
	int				life;
	t_clk			clk[TIC_NUMBER];
	clock_t			sound;
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

#endif
