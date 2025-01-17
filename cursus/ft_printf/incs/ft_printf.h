/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:47:30 by yekim             #+#    #+#             */
/*   Updated: 2020/11/05 12:27:47 by yekim            ###   ########.fr       */
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
	int			pad_len;
	int			point;
	int			space_len;
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
# define ASTERISK	-3
# define MINUS_PREC	-2
# define MALLOC_ERR	-1
# define SIGN_MINUS	1

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
int				printf_c(const char c, t_info *info);
int				printf_s(const char *str, t_info *info);
int				printf_p(const void *addr, t_info *info);

/*
***************************   printf_type2   *******************************
*/
int				printf_d(const int dec, t_info *info);
int				printf_u(const unsigned int dec, t_info *info);
int				printf_x(const unsigned int dec, t_info *info, char *base_type);

/*
***************************   printf_disp    *******************************
*/
void			set_pad_space(t_info *info);
int				print_signed_num(const char *str, t_info *info);
int				print_unsigned_num(const char *str, t_info *info);
int				print_string(const char *str, t_info *info);

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
char			*gen_nbr_str(unsigned long nbr, const char *base_type);
char			*add_prefix(const char *prefix, const char *str);
char			*add_sign(const char *nbr_str, t_info *info);

#endif
