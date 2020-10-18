/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:00:58 by yekim             #+#    #+#             */
/*   Updated: 2020/10/18 15:44:14 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pad_width(char pad, int width)
{
	int	ret;

	ret = 0;
	while (ret < width - 1)
	{
		ft_putchar_fd(pad, STD_OUT);
		++ret;
	}
	return (ret);
}

int		printf_char(int c, const t_info *info)
{
	int	ret;

	ret = 0;
	if (info->flag == INFO_INIT || info->flag == FLAG_PLUS)
	{
		ret += pad_width(' ', info->width);
		ft_putchar_fd((char)c, STD_OUT);
		++ret;
	}
	if (info->flag == FLAG_MINUS)
	{
		ft_putchar_fd((char)c, STD_OUT);
		++ret;
		ret += pad_width(' ', info->width);
	}
	return (ret);
}
