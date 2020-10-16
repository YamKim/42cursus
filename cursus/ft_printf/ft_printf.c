/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:47:36 by yekim             #+#    #+#             */
/*   Updated: 2020/10/16 17:21:14 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void simple_printf(char *format, ...) {
	va_list ap;

	va_start(ap, format);
	while (*format) {
		if (*format == '%') {
			++format;
			if (*format == 'd') {
				int num = va_arg(ap, int);
				ft_putnbr_fd(num, 1);	
			}
			if (*format == 's') {
				char *str = va_arg(ap, char *);
				ft_putstr_fd(str, 1);
			}
		}
		else
			ft_putchar_fd(*format, 1);
		++format;
	}
}

#include <stdio.h>
int get_width_prec_info(const char **format, t_info *info)
{


}


int	get_flag_info(const char **format, t_info *info)
{
	if (**format == ' ')
		info->flag = 1;
	else if (**format == '0')
		info->flag = 2;
	else if (**format == '+')
		info->flag = 3;
	else if (**format == '-')
		info->flag = 4;
	if (info->flag != 0)
		++(*format);
	while (ft_isdigit((int)**format))
	{
		++(info->width);
		++(*format);
	}
#if 0
	if (**format == '.')
	{
		while (ft_isdigit((int)**format))
		{
			++(info->precision);
			++format;
		}
	}
#endif
	return (1);
}

#if 1
int ft_printf(const char *format, ... ) {
	va_list	ap;
	t_info infoEx;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			// % 발견하면 일단 다음 한칸 넘기기 
			++format;
			// get_info 들어가기 전에 info 초기화해주기
			infoEx.flag = 0;
			infoEx.width = 0;
			infoEx.precision = 0;
			get_info(&format, &infoEx);	
			printf("flag: %d, width: %d, precision: %d\n", infoEx.flag, infoEx.width, infoEx.precision);
			printf("next_format\n");
			printf("%s", format);
			break;
		}
		ft_putchar_fd(*format, 0);
		++format;
	}
	return (1);
}
#endif

int main(void) {
	//char *format = ft_strdup("Hello %d %s!");	
	//simple_printf(format, 42, "World");
	//printf("printf result\n");
	//printf("Hello %-d %s\n", -42, "World");
	printf("ft_printf result\n");
	ft_printf("Hello %-3d %s\n", -42, "World");
#if 0
	int a = printf("This is % 5d\n", 24);
	printf("a: %d\n", a);
#endif

	return (0);
}
