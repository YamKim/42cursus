/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:43:57 by yekim             #+#    #+#             */
/*   Updated: 2020/10/04 19:00:47 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int	len_dest;
	int	len_src;
	int	itr;

	len_dest = 0;
	len_src = ft_strlen((char *)src);
	while (*dest)
	{
		++dest;
		++len_dest;
	}
	if (size <= (size_t)len_dest)
		return ((size_t)len_src + size);
	itr = (int)size - len_dest + 1;
	while (*src && --itr)
		*(dest++) = *(src++);
	*dest = '\0';
	return (size_t)(len_src + len_dest);
}
