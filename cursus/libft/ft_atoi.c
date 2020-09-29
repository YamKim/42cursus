/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:23:43 by yekim             #+#    #+#             */
/*   Updated: 2020/09/29 18:23:44 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r'
			|| c == '\t' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	ret;
	unsigned int	sign;

	sign = 0;
	while (ft_isspace(*nptr))
		++nptr;
	while (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			++sign;
		++nptr;
	}
	ret = 0;
	while (ft_isdigit(*nptr))
		ret = ret * 10 + (int)(*(nptr++) - '0');
	return (sign % 2 == 0 ? ret : -ret);
}
