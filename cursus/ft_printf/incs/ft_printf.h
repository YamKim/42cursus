/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:47:30 by yekim             #+#    #+#             */
/*   Updated: 2020/10/29 20:10:21 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

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
	int			width_flag;
	int			pad_len;
	int			space_len;
	int			prec;
	int			prec_flag;
	char		type;
	int			len;
}				t_info;

# define FLAG_TYPE	" 0+-"
# define CONV_TYPE	"csdiupxX%"
# define BASE_HEX_LOWER	"0123456789abcdef"
# define BASE_HEX_UPPER	"0123456789ABCDEF"
# define BASE_DEC	"0123456789"
# define INFO_INIT	0
# define STD_OUT	1
# define ASTERISK	-1
# define MINUS_PREC	-2
# define WIDTH_FLAG	1	
# define PREC_FLAG	1	
# define MALLOC_ERR	-1
# define SIGN_MINUS	1
# define SIGN_PLUS	0

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
****************************   printf_type   *******************************
*/
int				printf_c(char c, const t_info *info);
int				printf_s(const char *str, const t_info *info);
int				printf_p(const void *addr, const t_info *info);

/*
***************************   printf_type2   *******************************
*/
int				printf_d(const int dec, t_info *info);
int				printf_u(const unsigned int dec, t_info *info);
int				printf_x(const unsigned int dec, t_info *info);

/*
****************************   printf_put    *******************************
*/
int				put_signed_num(const char *str, t_info *info);
int				put_unsigned_num(const char *str, t_info *info);
int				set_and_put(const char *str, const t_info *info);
int				put_space_and_str(const char *str, const t_info *info);

/*
***************************   printf_disp    *******************************
*/
void			set_pad_space(t_info *info);
int				put_signed_num(const char *str, t_info *info);
int				put_unsigned_num(const char *str, t_info *info);
int				put_char_string(const char *str, t_info *info);

/*
***************************   printf_disp2   *******************************
*/
int				put_pad_disp_space(const char *str, t_info *info);
int				put_space_pad_disp(const char *str, t_info *info);
int				put_zeroflag_disp(const char *str, t_info *info);
int				put_space_sign_pad_disp(const char *str, t_info *info);

/*
****************************   printf_calc    ******************************
*/
int				calc_max(int nbr1, int nbr2);
int				calc_min(int nbr1, int nbr2);
int				calc_abs(int nbr);

/*
****************************   printf_base    ******************************
*/
char			*gen_nbr_str(long long int nbr, const char *base_type);
char			*add_prefix(const char *prefix, const char *str);
char			*get_sign(const t_info *info);

#endif
