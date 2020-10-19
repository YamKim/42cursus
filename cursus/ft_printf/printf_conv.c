/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:38 by yekim             #+#    #+#             */
/*   Updated: 2020/10/19 12:47:00 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_char(char c, const t_info *info)
{
	int	ret;

	if (c == '\0')
	{
		write(STD_OUT, "\0", 1);
		return (1);
	}

	if (info->flag == FLAG_MINUS)
		ret = write_prec_pad(&c, info);
	else
		ret = write_pad_prec(&c, info);
	return (ret);
}

int	printf_str(const char* str, const t_info *info)
{
	int	ret;

	if (str == NULL)
	{
		write(STD_OUT, "(null)", 6);
		return (6);
	}
	if (info->flag == FLAG_MINUS)
		ret = write_prec_pad(str, info);
	else
		ret = write_pad_prec(str, info);
	return (ret);
}

#if 0
int	printf_addr(
#endif
