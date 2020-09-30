/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 06:35:48 by yekim             #+#    #+#             */
/*   Updated: 2020/10/01 08:00:14 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> /////////

size_t	pass_set(char *s, char const *set, int start, int dir)
{
	size_t	ret;

	ret = 0;
	while (s[start + ret] && ft_strchr(set, s[start + ret]))
		ret += dir;

	return (ret);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;

	first = pass_set((char *)s1, set, 0, 1);
	printf("first idx: %d\n", (int)first);
	printf("s1: %s\n", s1 + first);
	return (NULL);	
}
