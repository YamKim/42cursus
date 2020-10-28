/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:44:34 by yekim             #+#    #+#             */
/*   Updated: 2020/10/28 09:11:05 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

#if 0
int	printf_d(const int dec, const t_info *info)
{
	int		ret;
	char	*dec_str;
	char	*dec_str_without_sign;

	if (!(dec_str = gen_nbr_str(dec, BASE_DEC)))
		return (MALLOC_ERR);
	if (info->prec == 0 && dec == 0 && info->prec_flag)
		dec_str[0] = info->width == 0 ? '\0' : ' ';
	if (dec_str[0] == '-')
	{
		((t_info *)info)->sign = SIGN_MINUS;
		dec_str_without_sign = dec_str + 1;
	}
	else
	{
		((t_info *)info)->sign = SIGN_PLUS;
		dec_str_without_sign = dec_str;
	}
	((t_info *)info)->len = (int)ft_strlen(dec_str_without_sign);
	ret = put_space_and_str(dec_str_without_sign, info);
	free(dec_str);
	return (ret);
}
#endif

#if 1
#include <stdio.h>
int	printf_d(const int dec, t_info *info)
{
	int		ret;
	char	*dec_str;

	if (!(dec_str = gen_nbr_str(dec, BASE_DEC)))
		return (MALLOC_ERR);
	if (info->prec == 0 && dec == 0 && info->prec_flag)
		dec_str[0] = info->width == 0 ? '\0' : ' ';
	if (dec < 0)
		info->sign = SIGN_MINUS;
	if (info->flag.plus || info->flag.space)
		dec_str = add_prefix(get_sign(info), dec_str);
	info->len = (int)ft_strlen(dec_str);
	ret = put_sign_num(dec_str, (t_info *)info);
	free(dec_str);
	ret = 0;
	return (ret);
}
#endif

int	printf_u(const unsigned int dec, t_info *info)
{
	int		ret;
	char	*dec_str;

	if (!(dec_str = gen_nbr_str(dec, BASE_DEC)))
		return (MALLOC_ERR);
	if (info->prec == 0 && dec == 0 && info->prec_flag)
		dec_str[0] = info->width == 0 ? '\0' : ' ';
	((t_info *)info)->sign = SIGN_PLUS;
	((t_info *)info)->len = (int)ft_strlen(dec_str);
	ret = put_space_and_str(dec_str, info);
	free(dec_str);
	return (ret);
}

int	printf_x(const unsigned int dec, t_info *info)
{
	int		ret;
	char	*hex_str;

	if (info->type == 'x')
		if (!(hex_str = gen_nbr_str(dec, BASE_HEX_LOWER)))
			return (MALLOC_ERR);
	if (info->type == 'X')
		if (!(hex_str = gen_nbr_str(dec, BASE_HEX_UPPER)))
			return (MALLOC_ERR);
	if (info->prec == 0 && dec == 0 && info->prec_flag)
		hex_str[0] = info->width == 0 ? '\0' : ' ';
	((t_info *)info)->sign = SIGN_PLUS;
	((t_info *)info)->len = (int)ft_strlen(hex_str);
	ret = put_space_and_str(hex_str, info);
	free(hex_str);
	return (ret);
}
