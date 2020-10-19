/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:11:18 by yekim             #+#    #+#             */
/*   Updated: 2020/10/19 12:47:18 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_info(t_info *info)
{
	info->flag = INFO_INIT;
	info->width = INFO_INIT;
	info->prec = INFO_INIT;
}

void	set_asterisk(va_list *ap, t_info *info)
{
	int	tmp_width;
	int	tmp_prec;

	if (info->width == ASTERISK)
	{
		tmp_width = va_arg(*ap, int);
		if (tmp_width < 0)
		{
			info->width = calc_abs(tmp_width);
			info->flag = FLAG_MINUS;
		}
		else
			info->width = tmp_width;
	}
	if (info->prec == ASTERISK)
	{
		tmp_prec = va_arg(*ap, int);
		info->prec = calc_abs(tmp_prec);
		if (tmp_prec < 0)
			info->prec = MINUS_PREC;
	}
}

int		get_width_info(const char **format, t_info *info)
{
	if (**format == '*')
	{
		info->width = ASTERISK;
		++(*format);
		return (1);
	}
	while (ft_isdigit((int)**format))
	{
		info->width = info->width * 10 + (**format - '0');
		++(*format);
	}
	return (1);
}

int		get_prec_info(const char **format, t_info *info)
{
	if (**format == '.')
	{
		++(*format);
		if (**format == '*')
		{
			info->prec = ASTERISK;
			++(*format);
			return (1);
		}
		while (ft_isdigit((int)**format))
		{
			info->prec = info->prec * 10 + (**format - '0');
			++(*format);
		}
	}
	return (1);
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
	get_width_info(format, info);
	get_prec_info(format, info);
	info->conv = **format;
	return (1);
}
