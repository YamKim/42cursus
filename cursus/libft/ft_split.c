/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 06:00:43 by yekim             #+#    #+#             */
/*   Updated: 2020/10/02 06:46:25 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	handle_word(char **str, char c, char **ft_sp, int k)
{
	int		ret;
	int		word_len;
	char	*beg;

	ret = 0;
	word_len = 0;
	while (**str)
	{
		while (**str && (**str == c))
			++(*str);
		beg = *str;
		if (**str && (**str != c))
			++ret;
		while (**str && (**str != c))
		{
			++(*str);
			++word_len;
		}
		if (k >= 0)
			break ;
	}
	if (k >= 0)
		ft_sp[k] = ft_substr(beg, 0, word_len);
	return ((size_t)ret);
}

void			free_all(char **ret, int k)
{
	int	idx;

	idx = 0;
	while (idx < k)
	{
		free(ft_sp[idx]);
		++idx;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	size;
	int		k;
	char	*str_tmp1;
	char	*str_tmp2;

	str_tmp1 = (char *)s;
	size = handle_word(&str_tmp1, c, 0, -1);
	if (!(ret = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	ret[size] = NULL;
	k = 0;
	str_tmp2 = (char *)s;
	while (k < size)
	{
		handle_word(&str_tmp2, c, ret, k++);
		if (str_tmp2[k] == NULL)
		{
			free_all(ret, k);
			break ;
		}
	}
	return (ret);
}
