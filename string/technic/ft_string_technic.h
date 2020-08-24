#ifndef FT_STRIHG_TECHNIC_H
# define FT_STINRG_TECHNIC_H

#include <unistd.h>
#include <stdlib.h>
#include "../basic/ft_string_basic.h"
#include "../util/ft_string_check.h"

/* find string */
int		find_idx(char *str, char c)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		if (*(str++) == c)
			return (ret);	
		++ret;
	}
	return (-1);
}

char	*ft_strstr(char *str, char *to_find)
{
	while (*str)
	{
		if (!ft_strncmp(str, to_find, ft_strlen(to_find)))
			return (str);
		++str;
	}	
	return (NULL);	
}


// use double pointer to save the position of single pointer
int		word_handle(char **str, char *charset, char **ft_sp, int idx)
{
	char	*get_word(char *str, char *charset);
	int		ret;

	ret = 0;
	while (**str)
	{
		while (**str && is_charset(**str, charset))
			++(*str);
		if (**str && !is_charset(**str, charset))
		{
			// when 'idx' is greater or equal with 0, fill the word
			if (idx >= 0)
				ft_sp[idx] = get_word(*str, charset);
			// when 'idx' is -1 -> count word
			else
				++ret;
		}
		while (**str && !is_charset(**str, charset))
			++(*str);	
		if (idx >= 0)
			break;
	}
	return (ret);
}

char	*get_word(char *str, char *charset)
{
	int		idx;
	int		size;
	char	*ret;

	size = 0;
	while (str[size] && !is_charset(str[size], charset))
		++size;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	idx = -1;
	while (++idx < size)
		ret[idx] = str[idx];
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		size;
	int		idx;
	char	*str_tmp1;
	char	*str_tmp2;
		
	str_tmp1 = str;
	size = word_handle(&str_tmp1, charset, 0, -1);
	if (!(ret = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	ret[size] = NULL;
	idx = 0;
	str_tmp2 = str;
	while (idx < size)
		word_handle(&str_tmp2, charset, ret, idx++);
	return (ret);
}
#endif
