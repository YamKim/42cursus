/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:18:45 by yekim             #+#    #+#             */
/*   Updated: 2020/10/06 07:43:12 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	idx;
	size_t	len;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	while (s[idx])
	{
		ret[idx] = f(idx, s[idx]);
		++idx;
	}
	return (ret);
}
