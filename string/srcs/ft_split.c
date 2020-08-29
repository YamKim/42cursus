#include "ft_string.h"

int		is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *(charset++))
			return (1);
	}
	return (0);
}

int		handle_word(char **str, char *charset, char **ft_sp, int k)
{
	int		is_charset(char c, char *charset);
	char	*strdup_slice(char *src, int beg, int end);
	int		ret;
	int		word_len;
	char	*beg;

	ret = 0;
	word_len = 0;
	while (**str)
	{
		while (**str && is_charset(**str, charset))
			++(*str);
		beg = *str;
		if (**str && !is_charset(**str, charset))
			++ret;
		while (**str && !is_charset(**str, charset))
		{
			++(*str);
			++word_len;
		}
		if (k >= 0)
			break;
	}
	if (k >= 0)
		ft_sp[k] = strdup_slice(beg, 0, word_len - 1);
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	int		handle_word(char **str, char *charset, char **ft_sp, int k);
	char	**ret;
	int		size;
	int		k;
	char	*str_tmp1;
	char	*str_tmp2;
	
		
	str_tmp1 = str;
	size = handle_word(&str_tmp1, charset, 0, -1);
	if (!(ret = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	ret[size] = NULL;
	k = 0;
	str_tmp2 = str;
	while (k < size)
		handle_word(&str_tmp2, charset, ret, k++);
	return (ret);
}
