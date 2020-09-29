/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:44:00 by yekim             #+#    #+#             */
/*   Updated: 2020/09/29 17:44:01 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	ret;
	unsigned int	idx;

	ret = 0;
	idx = (unsigned int)size;
	while (*src && --idx)
	{
		*(dest++) = *(src++);
		++ret;
	}
	*dest = '\0';
	while (*(src++))
		++ret;
	return (ret);
}
