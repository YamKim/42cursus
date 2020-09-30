/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:31:22 by yekim             #+#    #+#             */
/*   Updated: 2020/09/30 18:42:46 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	idx;
	char	*ret;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	idx = ft_strlcpy(ret, s1, len + 1);
	ft_strlcpy(ret + idx, s2, len + 1);
	return (ret);
}
