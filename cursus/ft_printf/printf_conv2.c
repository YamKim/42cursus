/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 07:19:54 by yekim             #+#    #+#             */
/*   Updated: 2020/10/20 07:29:40 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_int(const int dec, const t_info *info)
{
	int		ret;
	char	*dec_str;

	if (!(dec_str = ft_itoa((int)dec)))
		return (MALLOC_ERR);
	
	if (info->flag == FLAG_MINUS)
		ret = write_prec_pad(dec_str, info);
	else
		ret = write_pad_prec(dec_str, info);
	free(dec_str);
	return (ret);
}
