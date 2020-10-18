/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:11:18 by yekim             #+#    #+#             */
/*   Updated: 2020/10/18 22:28:35 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_info(t_info *info)
{
	info->flag = INFO_INIT;
	info->width = INFO_INIT;
	info->prec = INFO_INIT;
}

int		get_width_prec_info(const char **format, t_info *info)
{
	while (ft_isdigit((int)**format))
	{
		info->width = info->width * 10 + (**format - '0');
		++(*format);
	}
	if (**format == '.')
	{
		++(*format);
		while (ft_isdigit((int)**format))
		{
			info->prec = info->prec * 10 + (**format - '0');
			++(*format);
		}
	}
	return (0);
}

int		get_info(const char **format, t_info *info)
{
	initialize_info(info);
	if (**format == ' ')
		info->flag = FLAG_SPACE;
	else if (**format == '0')
		info->flag = FLAG_ZERO;
	else if (**format == '+')
		info->flag = FLAG_PLUS;
	else if (**format == '-')
		info->flag = FLAG_MINUS;
	if (info->flag != 0)
		++(*format);
	get_width_prec_info(format, info);
	info->conv = **format;
	return (1);
}

