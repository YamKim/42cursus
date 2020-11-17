/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 07:05:15 by yekim             #+#    #+#             */
/*   Updated: 2020/11/18 07:16:52 by yekim            ###   ########.fr       */
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

typedef struct		s_info
{
	t_vecd			pos;
	t_vecd			dir;
	t_vecd			plane;
	void			*mlx;
	void			*win;
	double			trans_speed;
	double			rot_speed;
}					t_info;

/*
** FUNCTIONS ======================================
** player motion
*/
void				move_forward(t_info *info);
void				move_backward(t_info *info);
void				turn_left(t_info *info);
void				turn_right(t_info *info);

/*
** vector calc
*/
t_vecd				translate_vec(t_vecd pos, t_vecd dir, double trans);
t_vecd				rotate_vec(t_vecd dir, double theta);

#endif
