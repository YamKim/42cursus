/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:47:30 by yekim             #+#    #+#             */
/*   Updated: 2020/10/23 09:33:36 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_flag
{
	int			zero;
	int			minus;
	int			plus;
	int			space;
}				t_flag;

typedef struct	s_info
{
	t_flag		flag;
	int			sign;
	int			width;
	int			prec;
	char		conv;
	int			len;
}				t_info;

# define PAD_TYPE	"  0  "
# define FLAG_TYPE	" 0+-"
# define NUM_TYPE	"dif"
# define CONV_TYPE	"csdiupxX%"
# define BASE_HEX	"0123456789abcdef"
# define BASE_DEC	"0123456789"
# define INFO_INIT	0
# define STD_OUT	1
# define ASTERISK	-1
# define MINUS_PREC	-2
# define MALLOC_ERR	-1
# define SIGN_MINUS	-1
# define SIGN_PLUS	1

/*
******************************   ft_printf   ********************************
*/
int				ft_printf(const char *format, ...);

/*
*****************************   printf_info   ******************************
*/
void			initialize_info(t_info *info);
void			set_asterisk(va_list *ap, t_info *info);
void			get_info(const char **format, t_info *info);

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
int				put_space_and_str(const char *str, const t_info *info);
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
int				get_nbr_len(long long int nbr, const int base_size);
char			*gen_nbr_str(long long int nbr, const char *base_type);

#endif
