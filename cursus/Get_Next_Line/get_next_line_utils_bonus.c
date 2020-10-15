/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 06:46:54 by yekim             #+#    #+#             */
/*   Updated: 2020/10/16 06:46:56 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	ret;

	ret = 0;
	if (str == NULL)
		return (ret);
	while (*(str++))
		++ret;
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;

	if (s == NULL)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		if (s[idx] == (unsigned char)c)
			return ((char *)s + idx);
		++idx;
	}
	return (c == 0 ? (char *)s + idx : NULL);
}

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

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	len;

	len = ft_strlen((char *)s);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(ret, s, len + 1);
	return (ret);
}
