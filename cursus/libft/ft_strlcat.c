/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:43:57 by yekim             #+#    #+#             */
/*   Updated: 2020/10/06 07:42:12 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	itr;

	len_dest = 0;
	len_src = ft_strlen((char *)src);
	while (*dest)
	{
		++dest;
		++len_dest;
	}
	if (size <= len_dest)
		return (len_src + size);
	itr = size - len_dest + 1;
	while (*src && --itr)
		*(dest++) = *(src++);
	*dest = '\0';
	return (len_src + len_dest);
}
