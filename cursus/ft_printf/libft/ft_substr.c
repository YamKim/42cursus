/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:05:36 by yekim             #+#    #+#             */
/*   Updated: 2020/09/30 18:43:14 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*ret;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen((char *)s);
	if (start >= (unsigned int)len_s)
		return (ft_calloc(1, sizeof(char)));
	len = (len > (len_s - start)) ? (len_s - start) : len;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
