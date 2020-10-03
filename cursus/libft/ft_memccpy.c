/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:06:03 by yekim             #+#    #+#             */
/*   Updated: 2020/10/03 11:28:38 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (((unsigned char *)src)[idx] == (unsigned char)c)
			return (dest + idx + 1);
		++idx;
	}
	return (NULL);
}
