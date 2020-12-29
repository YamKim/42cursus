/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 06:51:52 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 06:52:05 by yekim            ###   ########.fr       */
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
		return (ft_strdup(""));
	len = (len > (len_s - start)) ? (len_s - start) : len;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
