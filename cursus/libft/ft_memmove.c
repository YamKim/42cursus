/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:06:16 by yekim             #+#    #+#             */
/*   Updated: 2020/10/04 19:52:26 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				idx;
	int				len;
	unsigned char	*uchar_src;
	unsigned char	*uchar_dest;

	if (dest == src || n == 0)
		return (dest);
	len = (int)n;
	idx = -1;
	uchar_src = (unsigned char*)src;
	uchar_dest = (unsigned char*)dest;
	if (dest >= src)
		while (++idx < len)
			uchar_dest[len - 1 - idx] = uchar_src[len - 1 - idx];
	else
		while (++idx < len)
			uchar_dest[idx] = uchar_src[idx];
	return (dest);
}
