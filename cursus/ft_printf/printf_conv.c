/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:38 by yekim             #+#    #+#             */
/*   Updated: 2020/10/21 17:53:37 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_char(char c, const t_info *info)
{
	int	ret;

	((t_info *)info)->len = sizeof(c);
	if (c == '\0')
	{
		write(STD_OUT, "\0", 1);
		return (1);
	}
	ret = put_space_and_str(&c, info);
	return (ret);
}

#include <stdio.h>
int	printf_str(const char *str, const t_info *info)
{
	int	ret;

	((t_info *)info)->len = (int)ft_strlen(str);
	if (str == NULL)
	{
		write(STD_OUT, "(null)", 6);
		return (6);
	}
	ret = put_space_and_str(str, info);
	return (ret);
}

int	printf_addr(const void *addr, const t_info *info)
{
	int		ret;
	char	*hex_str;

	((t_info *)info)->len = (int)ft_strlen(addr);
	ret = get_hex_len((unsigned long)addr, 1);
	if (!(hex_str = (char *)malloc(sizeof(char) * (ret + 1))))
		return (MALLOC_ERR);
	hex_str[ret] = '\0';
	get_hex_str((unsigned long)addr, hex_str, ret - 1, 1);
	hex_str = add_prefix("0x", hex_str);
	ret = put_space_and_str(hex_str, info);
	free(hex_str);
	return (ret);
}
