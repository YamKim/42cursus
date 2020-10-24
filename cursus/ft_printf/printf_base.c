/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:52:39 by yekim             #+#    #+#             */
/*   Updated: 2020/10/24 15:44:19 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_nbr_len(long long int nbr, const int base_size)
{
	int						ret;
	long long unsigned int	nbr_tmp;

	ret = 0;
	if (nbr < 0)
	{
		nbr_tmp = -nbr;
		ret += 1;
	}
	else
		nbr_tmp = nbr;
	while (nbr_tmp != 0)
	{
		nbr_tmp /= base_size;
		ret += 1;
	}
	return (ret);
}

#include <stdio.h>//
char	*gen_nbr_str(long long int nbr, const char *base_type)
{
	char					*ret;
	int						size;
	int						idx;
	int						base_size;
	long long unsigned int	nbr_tmp;

	if (nbr == 0)
		return (ft_strdup("0"));
	base_size = (int)ft_strlen(base_type);	
	size = get_nbr_len(nbr, base_size);
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size] = '\0';
	nbr_tmp = nbr < 0 ? -nbr : nbr;
	idx = size - 1;
	while (nbr_tmp)
	{
		ret[idx--] = base_type[nbr_tmp % base_size];
		nbr_tmp /= base_size;
	}
	ret[0] = nbr < 0 ? '-' : ret[0];
	return (ret);
}
