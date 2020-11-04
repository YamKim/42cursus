/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:11:18 by yekim             #+#    #+#             */
/*   Updated: 2020/11/04 18:33:01 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	initialize_info(t_info *info)
{
	info->flag.zero = 0;
	info->flag.minus = 0;
	info->flag.plus = 0;
	info->flag.space = 0;
	info->sign = 0;
	info->width = 0;
	info->prec = 0;
	info->point = 0;
	info->pad_len = 0;
	info->space_len = 0;
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
			info->flag.minus = 1;
		}
		else
			info->width = tmp_width;
	}
	if (info->prec == ASTERISK && info->point)
	{
		tmp_prec = va_arg(*ap, int);
		if (tmp_prec < 0)
		{
			info->prec = 0;
			info->point = 0;
		}
		else
			info->prec = tmp_prec;
	}
}

void	get_width_info(const char **format, t_info *info)
{
	if (**format == '*')
	{
		info->width = ASTERISK;
		++(*format);
		return ;
	}
	while (ft_isdigit((int)**format))
	{
		info->width = info->width * 10 + (**format - '0');
		++(*format);
	}
}

void	get_prec_info(const char **format, t_info *info)
{
	if (**format == '.')
	{
		info->point = 1;
		++(*format);
	}
	if (info->point)
	{
		if (**format == '*')
		{
			info->prec = ASTERISK;
			++(*format);
			return ;
		}
		while (ft_isdigit((int)**format))
		{
			info->prec = info->prec * 10 + (**format - '0');
			++(*format);
		}
	}
}

void	get_info(const char **format, t_info *info)
{
	initialize_info(info);
	while (**format != '\0' && ft_strchr(FLAG_TYPE, **format))
	{
		if (**format == '0' && info->width == 0)
			info->flag.zero = 1;
		else if (**format == '-')
			info->flag.minus = 1;
		else if (**format == '+')
			info->flag.plus = 1;
		else if (**format == ' ')
			info->flag.space = 1;
		++(*format);
	}
	get_width_info(format, info);
	get_prec_info(format, info);
	info->type = **format;
}
