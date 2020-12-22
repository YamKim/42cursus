/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:47:49 by yekim             #+#    #+#             */
/*   Updated: 2020/12/22 11:04:32 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*ret;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen((char *)s);
	if (start >= (unsigned int)len_s)
		return (ft_strdup(""));
	len = (len > (len_s - start)) ? (len_s - start) : len;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
		((unsigned char *)s)[idx++] = '\0';
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ucsrc;
	unsigned char	*ucdest;

	if (dest == NULL && src == NULL)
		return (NULL);
	ucsrc = (unsigned char *)src;
	ucdest = (unsigned char *)dest;
	while (n--)
		*(ucdest++) = *(ucsrc++);
	return (dest);
}
