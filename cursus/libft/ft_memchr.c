/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:06:06 by yekim             #+#    #+#             */
/*   Updated: 2020/10/04 09:17:34 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	idx;

	idx = 0;
	while ((size_t)idx < n)
	{
		if (((unsigned char *)s)[idx] == (unsigned char)c)
			return ((void *)s + idx);
		++idx;
	}
	return (NULL);
}
