/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:06:16 by yekim             #+#    #+#             */
/*   Updated: 2020/10/03 20:23:11 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	idx;
	int	len;

	if (dest == src || n == 0)
		return (dest);
	len = (int)n;
	idx = -1;
	if (dest >= src)
		while (++idx < len)
			((unsigned char *)dest)[len - 1 - idx] 
				= ((unsigned char *)src)[len - 1 - idx];
	else
		while (++idx < len)
			((unsigned char *)dest)[idx] 
				= ((unsigned char *)src)[idx];
	return (dest);
}
