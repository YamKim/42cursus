/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:47:36 by yekim             #+#    #+#             */
/*   Updated: 2020/10/18 15:43:14 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		print_va(va_list ap, const t_info *info)
{
	int		ret;
	
	if (info->conversion == 'c') 
		ret = printf_char(va_arg(ap, int), info); 
	if (info->conversion == 's')
		ret = printf_str(va_arg(ap, char *), info); 
		
	return (ret);
}

#include <stdio.h>
int ft_printf(const char *format, ... ) {
	va_list	ap;
	t_info	info;
	int		ret;

	va_start(ap, format);
	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			// % 발견하면 일단 다음 한칸 넘기기 
			++format;
			// get_info 들어가기 전에 info 초기화해주기
			initialize_info(&info);
			get_info(&format, &info);	
		//	printf("flag: %d, width: %d\n", info.flag, info.width);
		//	printf("precision: %d, conversion: %c\n", info.precision, info.conversion);
			ret += print_va(ap, &info);
			// conversion 출력 skip
			++format;
		}
		ft_putchar_fd(*format, STD_OUT);
		++ret;
		++format;
	}
	return (ret);
}

