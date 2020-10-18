/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:47:30 by yekim             #+#    #+#             */
/*   Updated: 2020/10/18 15:49:47 by yekim            ###   ########.fr       */
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
	int			precision;
	char		conversion;
}				t_info;

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

/*
*****************************   MAIN FUNCTION   *******************************
*/
int				ft_printf(const char *format, ...);

/*
*****************************   FLAG FUNCTION   *******************************
*/
void			initialize_info(t_info *info);
int				get_width_prec_info(const char **format, t_info *info);
int				get_info(const char **format, t_info *info);
#endif


/*
**************************   PRINT CHAR FUNCTION   ****************************
*/
int				printf_char(int c, const t_info *info);

/*
**************************   PRINT STR FUNCTION    ****************************
*/
int				printf_str(const char* str, const t_info *info);
