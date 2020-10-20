/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 07:19:54 by yekim             #+#    #+#             */
/*   Updated: 2020/10/20 12:34:31 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_int(const int dec, const t_info *info)
{
	int		ret;
	char	*dec_str;

	if (!(dec_str = ft_itoa((int)dec)))
		return (MALLOC_ERR);
	if (dec_str[0] != '-')
	{
		if (info->flag.plus)
			dec_str = add_prefix("+", dec_str);
		else if (info->flag.space)
			dec_str = add_prefix(" ", dec_str);
	}
	if (info->flag.minus)
		ret = write_prec_pad(dec_str, info);
	else
		ret = write_pad_prec(dec_str, info);
	free(dec_str);
	return (ret);
}
