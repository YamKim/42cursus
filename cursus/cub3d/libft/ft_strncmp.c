/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 06:51:27 by yekim             #+#    #+#             */
/*   Updated: 2021/01/01 12:05:11 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	idx = 0;
	while ((us1[idx] || us2[idx]) && idx < n)
	{
		if (us1[idx] != us2[idx])
			break ;
		++idx;
	}
	return (idx == n ? 0 : (int)(us1[idx] - us2[idx]));
}
