/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:52:39 by yekim             #+#    #+#             */
/*   Updated: 2020/10/20 08:19:58 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_hex_len(unsigned long dec, int first_zero)
{
	int		ret;

	ret = 0;
	if (dec == 0)
	{
		if (first_zero)
			return (1);
		return (ret);
	}
	ret = 1 + get_hex_len(dec / 16, 0);
	return (ret);
}

int	get_hex_str(unsigned long dec, char *hex_str, int idx, int first_zero)
{
	int		ret;

	ret = 0;
	if (dec == 0)
	{
		if (first_zero)
			hex_str[idx] = '0';
		return (ret);
	}
	hex_str[idx] = HEX_BASE[dec % 16];
	ret = 1 + get_hex_str(dec / 16, hex_str, idx - 1, 0);
	return (ret);
}