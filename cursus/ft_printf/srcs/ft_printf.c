/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:47:36 by yekim             #+#    #+#             */
/*   Updated: 2020/10/31 16:57:19 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	print_va(va_list *ap, t_info *info)
{
	int		ret;

	set_asterisk(ap, (t_info *)info);
	if (info->type == '%')
		ret = printf_c('%', info);
	if (info->type == 'c')
		ret = printf_c((char)va_arg(*ap, int), info);
	if (info->type == 's')
		ret = printf_s(va_arg(*ap, char *), info);
	if (info->type == 'p')
		ret = printf_p(va_arg(*ap, void *), info);
	if (info->type == 'd' || info->type == 'i')
		ret = printf_d(va_arg(*ap, int), (t_info *)info);
	if (info->type == 'u')
		ret = printf_u(va_arg(*ap, int), (t_info *)info);
	if (info->type == 'x')
		ret = printf_x(va_arg(*ap, int), (t_info *)info, BASE_HEX_LOWER);
	if (info->type == 'X')
		ret = printf_x(va_arg(*ap, int), (t_info *)info, BASE_HEX_UPPER);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_info	info;
	int		ret;

	va_start(ap, format);
	ret = 0;
	while (*format)
	{
		if (*format != '%')
			ret += write(STD_OUT, format++, 1);
		else
		{
			++format;
			get_info(&format, &info);
			ret += print_va(&ap, &info);
			++format;
		}
	}
	return (ret);
}
