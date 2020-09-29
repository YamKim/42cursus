/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:43:57 by yekim             #+#    #+#             */
/*   Updated: 2020/09/29 17:43:58 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	len;
	unsigned int	src_len;
	unsigned int	itr;

	len = 0;
	src_len = ft_strlen(src);
	while (*dest)
	{
		++dest;
		++len;
	}
	if (size <= (size_t)len)
		return ((size_t)src_len + size);
	itr = (unsigned int)size - len + 1;
	while (*src && --itr)
		*(dest++) = *(src++);
	*dest = '\0';
	return (src_len + len);
}
