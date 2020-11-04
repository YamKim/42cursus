/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:52:39 by yekim             #+#    #+#             */
/*   Updated: 2020/11/04 18:23:15 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int		get_nbr_len(unsigned long nbr, const int base_size)
{
	int						ret;

	ret = 0;
	while (nbr != 0)
	{
		nbr /= base_size;
		ret += 1;
	}
	return (ret);
}

char	*gen_nbr_str(unsigned long nbr, const char *base_type)
{
	char	*ret;
	int		size;
	int		idx;
	int		base_size;

	if (nbr == 0)
		return (ft_strdup("0"));
	base_size = (int)ft_strlen(base_type);
	size = get_nbr_len(nbr, base_size);
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size] = '\0';
	idx = size - 1;
	while (nbr)
	{
		ret[idx--] = base_type[nbr % base_size];
		nbr /= base_size;
	}
	return (ret);
}

char	*add_prefix(const char *prefix, const char *str)
{
	char	*ret;

	ret = ft_strjoin(prefix, str);
	free((char *)str);
	return (ret);
}

char	*add_sign(const char *nbr_str, t_info *info)
{
	char	*ret;

	ret = NULL;
	info->len += 1;
	if (info->flag.plus)
		ret = add_prefix("+", nbr_str);
	else if (info->flag.space)
		ret = add_prefix(" ", nbr_str);
	else if (info->sign == SIGN_MINUS)
		ret = add_prefix("-", nbr_str);
	return (ret);
}
