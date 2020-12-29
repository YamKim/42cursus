/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:32:21 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 10:32:49 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTILS_H
# define _UTILS_H

# include <time.h>
# define TEXTURE_ANI_NUMBER 5

typedef struct		s_tex
{
	void			*ptr;
	int				*data;
	int				w;
	int				h;
}					t_tex;

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
#endif
