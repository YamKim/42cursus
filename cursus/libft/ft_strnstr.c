/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:44:09 by yekim             #+#    #+#             */
/*   Updated: 2020/09/29 17:44:09 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle)
{
	while (*haystack)
	{
		if (!ft_strncmp(haystack, needle, ft_strlen((char *)needle)))
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}
