/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:44:21 by yekim             #+#    #+#             */
/*   Updated: 2020/11/01 14:14:36 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	printf_c(const char c, t_info *info)
{
	int	ret;

	if (info->prec > 0 && info->point)
		return (-1);
	ret = 0;
	info->len = 1;
	info->space_len = calc_max(info->width - info->len, 0);
	if (info->flag.minus)
	{
		ret += write(STD_OUT, &c, 1);
		while (info->space_len-- > 0)
			ret += write(STD_OUT, " ", 1);
	}
	else
	{
		while (info->space_len-- > 0)
			ret += write(STD_OUT, " ", 1);
		ret += write(STD_OUT, &c, 1);
	}
	return (ret);
}

int	printf_s(const char *str, t_info *info)
{
	int	ret;

	if (str == NULL)
	{
		info->len = 6;
		ret = put_char_string("(null)", (t_info *)info);
		return (ret);
	}
	info->len = (int)ft_strlen(str);
	ret = put_char_string(str, (t_info *)info);
	return (ret);
}

int	printf_p(const void *addr, t_info *info)
{
	int		ret;
	char	*addr_nbr;

	if (!(addr_nbr = gen_nbr_str((unsigned long)addr, BASE_HEX_LOWER)))
		return (-1);
	if (info->point == 1 && info->prec == 0 && (unsigned long)addr == 0)
		addr_nbr[0] = '\0';
	addr_nbr = add_prefix("0x", addr_nbr);
	((t_info *)info)->len = (int)ft_strlen(addr_nbr);
	ret = put_char_string(addr_nbr, (t_info *)info);
	free(addr_nbr);
	return (ret);
}
