/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 07:19:54 by yekim             #+#    #+#             */
/*   Updated: 2020/10/25 08:02:45 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>//
int	printf_d(const int dec, const t_info *info)
{
	int		ret;
	char	*dec_str;
	char	*dec_str_without_sign;

	if (!(dec_str = gen_nbr_str(dec, BASE_DEC)))
		return (MALLOC_ERR);
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

int	printf_u(const unsigned int dec, const t_info *info)
{
	int		ret;
	char	*dec_str;

	if (!(dec_str = gen_nbr_str(dec, BASE_DEC)))
		return (MALLOC_ERR);
	((t_info *)info)->sign = SIGN_PLUS;
	((t_info *)info)->len = (int)ft_strlen(dec_str);
	ret = put_space_and_str(dec_str, info);
	free(dec_str);
	return (ret);
}

int	printf_x(const unsigned int dec, const t_info *info)
{
	int		ret;
	char	*hex_str;

	if (info->conv == 'x')
		if (!(hex_str = gen_nbr_str(dec, BASE_HEX_LOWER)))
			return (MALLOC_ERR);
	if (info->conv == 'X')
		if (!(hex_str = gen_nbr_str(dec, BASE_HEX_UPPER)))
			return (MALLOC_ERR);
	((t_info *)info)->sign = SIGN_PLUS;
	((t_info *)info)->len = (int)ft_strlen(hex_str);
	ret = put_space_and_str(hex_str, info);
	free(hex_str);
	return (ret);
}
