/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 07:19:54 by yekim             #+#    #+#             */
/*   Updated: 2020/10/21 11:50:27 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_int(const int dec, const t_info *info)
{
	int		ret;
	char	*dec_str;

	if (!(dec_str = ft_itoa((int)dec)))
		return (MALLOC_ERR);
	((t_info *)info)->sign = dec_str[0] == '-' ? SIGN_MINUS : SIGN_PLUS;
	if (info->flag.plus)
		dec_str = add_prefix("+", dec_str);
	else if (info->flag.space)
		dec_str = add_prefix(" ", dec_str);
	((t_info *)info)->len = (int)ft_strlen(dec_str);
	ret = put_space_and_str(dec_str, info);
	free(dec_str);
	return (ret);
}
