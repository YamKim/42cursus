/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:44:34 by yekim             #+#    #+#             */
/*   Updated: 2020/11/05 12:51:20 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	printf_d(const int dec, t_info *info)
{
	int				ret;
	char			*dec_str;
	unsigned int	udec;

	if (dec < 0)
	{
		info->sign = SIGN_MINUS;
		udec = -dec;
	}
	else
		udec = dec;
	if (!(dec_str = gen_nbr_str(udec, BASE_DEC)))
		return (MALLOC_ERR);
	if (info->point == 1 && info->prec == 0 && dec == 0)
		dec_str[0] = '\0';
	info->len = (int)ft_strlen(dec_str);
	if (info->flag.plus || info->flag.space || info->sign == SIGN_MINUS)
		dec_str = add_sign(dec_str, info);
	if (info->flag.plus || info->flag.space || info->sign == SIGN_MINUS)
		ret = print_signed_num(dec_str, info);
	else
		ret = print_unsigned_num(dec_str, info);
	free(dec_str);
	return (ret);
}

int	printf_u(const unsigned int dec, t_info *info)
{
	int		ret;
	char	*dec_str;

	if (!(dec_str = gen_nbr_str(dec, BASE_DEC)))
		return (MALLOC_ERR);
	if (info->point == 1 && info->prec == 0 && dec == 0)
		dec_str[0] = '\0';
	info->len = (int)ft_strlen(dec_str);
	ret = print_unsigned_num(dec_str, info);
	free(dec_str);
	return (ret);
}

int	printf_x(const unsigned int dec, t_info *info, char *base_type)
{
	int		ret;
	char	*hex_str;

	if (!(hex_str = gen_nbr_str(dec, base_type)))
		return (MALLOC_ERR);
	if (info->point == 1 && info->prec == 0 && dec == 0)
		hex_str[0] = '\0';
	info->len = (int)ft_strlen(hex_str);
	ret = print_unsigned_num(hex_str, info);
	free(hex_str);
	return (ret);
}
