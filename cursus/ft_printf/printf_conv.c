/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:03:38 by yekim             #+#    #+#             */
/*   Updated: 2020/10/24 23:22:04 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_c(char c, const t_info *info)
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

int	printf_s(const char *str, const t_info *info)
{
	int	ret;

	((t_info *)info)->len = (int)ft_strlen(str);
	if (info->len == 0)
	{
		write(STD_OUT, "(null)", 6);
		return (6);
	}
	ret = put_space_and_str(str, info);
	return (ret);
}

#include <stdio.h> //
int	printf_p(const void *addr, const t_info *info)
{
	int		ret;
	char	*addr_nbr;

	if (!(addr_nbr = gen_nbr_str((unsigned long)addr, BASE_HEX_LOWER)))
		return (-1);
	addr_nbr = add_prefix("0x", addr_nbr);
	((t_info *)info)->len = (int)ft_strlen(addr_nbr);
	ret = put_space_and_str(addr_nbr, info);
	free(addr_nbr);
	return (ret);
}
