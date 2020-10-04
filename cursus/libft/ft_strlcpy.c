/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:44:00 by yekim             #+#    #+#             */
/*   Updated: 2020/10/04 18:26:36 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	ret;
	int	itr;

	ret = 0;
	itr = (int)size;
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
