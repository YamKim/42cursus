/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:44:21 by yekim             #+#    #+#             */
/*   Updated: 2020/11/04 18:08:26 by yekim            ###   ########.fr       */
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
	ret = print_string(&c, info);
	return (ret);
}

int	printf_s(const char *str, t_info *info)
{
	int	ret;

	if (str == NULL)
	{
		info->len = 6;
		ret = print_string("(null)", (t_info *)info);
		return (ret);
	}
	info->len = (int)ft_strlen(str);
	ret = print_string(str, info);
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
	info->len = (int)ft_strlen(addr_nbr);
	ret = print_string(addr_nbr, info);
	free(addr_nbr);
	return (ret);
}
