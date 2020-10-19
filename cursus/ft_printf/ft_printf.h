/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:47:30 by yekim             #+#    #+#             */
/*   Updated: 2020/10/20 08:18:53 by yekim            ###   ########.fr       */
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

# define PAD_TYPE	"  0  "
# define HEX_BASE	"0123456789abcdef"
# define INFO_INIT	0
# define FLAG_SPACE	1
# define FLAG_ZERO	2
# define FLAG_PLUS	3
# define FLAG_MINUS	4
# define STD_OUT	1
# define ASTERISK	-1
# define MINUS_PREC	-2
# define MALLOC_ERR	-1

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
int				printf_addr(const void *addr, const t_info *info);

/*
***************************   printf_conv2   *******************************
*/
int				printf_int(const int dec, const t_info *info);

/*
***************************   printf_utils    ******************************
*/
int				write_pad_prec(const char *str, const t_info *info);
int				write_prec_pad(const char *str, const t_info *info);
char			*add_prefix(const char *prefix, const char *str);

/*
****************************   printf_calc    ******************************
*/
int				calc_max(int nbr1, int nbr2);
int				calc_min(int nbr1, int nbr2);
int				calc_abs(int nbr);

/*
****************************   printf_base    ******************************
*/
int				get_hex_len(unsigned long dec, int first_zero);
int				get_hex_str(unsigned long dec, char *hex_str, int idx, int first_zero);

#endif
