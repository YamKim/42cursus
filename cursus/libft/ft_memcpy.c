/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:06:13 by yekim             #+#    #+#             */
/*   Updated: 2020/09/29 16:06:14 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	idx;

	if (dest == NULL || src == NULL)
		return (NULL);
	idx = 0;
	while (idx < n)
	{
		((unsigned char *)dest)[idx] = ((unsigned char *)src)[idx];
		++idx;
	}
	return (dest);
}
