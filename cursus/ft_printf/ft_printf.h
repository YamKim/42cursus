/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:47:30 by yekim             #+#    #+#             */
/*   Updated: 2020/10/19 12:37:36 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_info
{
	int			flag;
	int			width;
	int			prec;
	char		conv;
}				t_info;

# define PAD_TYPE		"  0  "
# ifndef INFO_INIT
#  define INFO_INIT		0
# endif
# ifndef FLAG_SPACE
#  define FLAG_SPACE	1
# endif
# ifndef FLAG_ZERO
#  define FLAG_ZERO		2
# endif
# ifndef FLAG_PLUS
#  define FLAG_PLUS		3
# endif
# ifndef FLAG_MINUS
#  define FLAG_MINUS	4
# endif
# ifndef STD_OUT
#  define STD_OUT		1
# endif
# ifndef ASTERISK
#  define ASTERISK		-1
# endif
# define MINUS_PREC		-2

/*
******************************   ft_printf   ********************************
*/
int				ft_printf(const char *format, ...);

/*
*****************************   printf_info   ******************************
*/
void			initialize_info(t_info *info);
void			set_asterisk(va_list *ap, t_info *info);
int				get_info(const char **format, t_info *info);

/*
****************************   printf_conv   *******************************
*/
int				printf_char(char c, const t_info *info);
int				printf_str(const char *str, const t_info *info);

/*
***************************   printf_utils    ******************************
*/
int				write_pad_prec(const char *str, const t_info *info);
int				write_prec_pad(const char *str, const t_info *info);

/*
****************************   printf_calc    ******************************
*/
int	calc_max(int nbr1, int nbr2);
int	calc_min(int nbr1, int nbr2);
int	calc_abs(int nbr);

#endif
