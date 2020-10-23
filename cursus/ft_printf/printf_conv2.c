/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 07:19:54 by yekim             #+#    #+#             */
/*   Updated: 2020/10/22 19:08:23 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
int	printf_int(const int dec, const t_info *info)
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
