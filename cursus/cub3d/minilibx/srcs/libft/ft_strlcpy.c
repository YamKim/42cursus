/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 06:50:45 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 10:40:55 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ret;
	size_t	len_src;

	ret = 0;
	if (src == NULL)
		return (ret);
	len_src = ft_strlen(src);
	if (dest == NULL || size == 0)
		return (len_src);
	while (ret < len_src && ret < size - 1)
	{
		dest[ret] = src[ret];
		++ret;
	}
	dest[ret] = '\0';
	return (len_src);
}
