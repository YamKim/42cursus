/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:47:36 by yekim             #+#    #+#             */
/*   Updated: 2020/10/22 18:22:31 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_va(va_list *ap, const t_info *info)
{
	int		ret;
	
	set_asterisk(ap, (t_info *)info);
	if (info->conv == 'c') 
		ret = printf_char((char)va_arg(*ap, int), info); 
	if (info->conv == 's')
		ret = printf_str(va_arg(*ap, char *), info); 
	if (info->conv == 'p')
		ret = printf_addr(va_arg(*ap, void *), info); 
	if (info->conv == 'd' || info->conv == 'i')
		ret = printf_int(va_arg(*ap, int), (t_info *)info); 
#if 0
	if (info->conv == 'x' || info->conv == 'X' || info->conv == 'u')
#endif
		
		
		
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
		if (*format != '%')
			ret += write(STD_OUT, format++, 1); 
		else 
		{
			// % 발견하면 일단 다음 한칸 넘기기 
			++format;
			// get_info 들어가기 전에 info 초기화해주기
			initialize_info(&info);
			get_info(&format, &info);
			ret += print_va(&ap, &info);
			// conversion 출력 skip
			++format;
		}
	}
//	printf("plus: %d, minus: %d, zero: %d, space: %d\n", info.flag.plus, info.flag.minus, info.flag.zero, info.flag.space);

//	printf("precision: %d, conversion: %c\n", info.prec, info.conv);
	return (ret);
}

