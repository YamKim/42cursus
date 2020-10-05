/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:44:09 by yekim             #+#    #+#             */
/*   Updated: 2020/10/04 20:41:25 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int	len_haystack;
	int len_needle;
	int count;

	count = 0;
	len_haystack = ft_strlen((char *)haystack);
	len_haystack = len_haystack <= n ? n : len_haystack; 
	len_needle = ft_strlen((char *)nedle);
	if (len_needle > len_haystack)
		return (NULL);
	while (*haystack)
	{
		if (!ft_strncmp(haystack, needle, ft_strlen((char *)needle)))
			return ((char *)haystack);
		++haystack;
		++count;
		if (count >= (len_haystack - len_needle))
			break ;
	}
	return (NULL);
}
