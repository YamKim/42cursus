/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:44:00 by yekim             #+#    #+#             */
/*   Updated: 2020/10/06 07:42:30 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ret;
	size_t	itr;

	ret = 0;
	itr = size;
	while (*src && --itr)
	{
		*(dest++) = *(src++);
		++ret;
	}
	*dest = '\0';
	while (*(src++))
		++ret;
	return (ret);
}
