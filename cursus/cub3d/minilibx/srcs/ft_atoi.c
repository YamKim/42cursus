/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:50:00 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 06:07:09 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static int	ft_isspace(const char c)
{
	if (c == '\f' || c == '\n' || c == '\r'
			|| c == '\t' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *nptr)
{
	unsigned int	ret;
	int				sign;

	sign = 0;
	while (ft_isspace(*nptr))
		++nptr;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			++sign;
		++nptr;
	}
	ret = 0;
	while (*nptr >= 48 && *nptr <= 57)
		ret = ret * 10 + (unsigned int)(*(nptr++) - '0');
	if (sign % 2 == 0)
		return ((int)ret);
	return (-ret);
}
