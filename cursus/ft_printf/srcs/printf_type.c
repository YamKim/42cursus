/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:44:21 by yekim             #+#    #+#             */
/*   Updated: 2020/10/29 17:18:12 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	printf_c(char c, const t_info *info)
{
	int	ret;

	((t_info *)info)->len = sizeof(c);
	if (c == '\0')
		return (write(STD_OUT, "\0", 1));
	ret = put_char_string(&c, (t_info *)info);
	return (ret);
}

int	printf_s(const char *str, const t_info *info)
{
	int	ret;

	if (str == NULL)
		return (0);
	((t_info *)info)->len = (int)ft_strlen(str);
	if (info->len == 0)
		return (0);
	ret = put_char_string(str, (t_info *)info);
	return (ret);
}

int	printf_p(const void *addr, const t_info *info)
{
	int		ret;
	char	*addr_nbr;

	if (!(addr_nbr = gen_nbr_str((unsigned long)addr, BASE_HEX_LOWER)))
		return (-1);
	if (info->prec == 0 && (unsigned long)addr == 0 && info->prec_flag)
		addr_nbr[0] = info->width == 0 ? '\0' : ' ';
	addr_nbr = add_prefix("0x", addr_nbr);
	((t_info *)info)->len = (int)ft_strlen(addr_nbr);
	ret = put_space_and_str(addr_nbr, info);
	free(addr_nbr);
	return (ret);
}
