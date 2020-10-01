/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 06:35:48 by yekim             #+#    #+#             */
/*   Updated: 2020/10/02 06:31:35 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	pass_set(char *s, char const *set, int start, int dir)
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
	size_t	last;
	size_t	len_s1;
	size_t	len_ret;
	char	*ret;

	first = pass_set((char *)s1, set, 0, 1);
	len_s1 = ft_strlen((char *)s1);
	last = len_s1 + pass_set((char *)s1, set, len_s1 - 1, -1);
	len_ret = last - first;
	if (!(ret = (char *)malloc(sizeof(char) * len_ret + 1)))
		return (NULL);
	ft_strlcpy(ret, (char *)s1 + first, len_ret + 1);
	return (ret);
}
