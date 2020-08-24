#ifndef FT_STRING_CHECK_H
# define FT_STRING_CHECK_H

#include "ft_string_check.h"

/* check string */
int	is_space(char c)
{
	if (c == '\f' || c == '\n' || c == '\r'
			|| c == '\t' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_uniq_str(char *str)
{
	char	*tmp;

	while (*str)
	{
		tmp = str + 1;
		while (*tmp)
		{
			if (*tmp == *str)
				return (0);
			++tmp;
		}
		++str;
		tmp = str;
	}
	return (1);
}

int	check_base(char *base)
{
	char	c;

	if (!base[0] || !base[1])
		return (0);
	if(!is_uniq_str(base))
		return (0);
	while (*base)
	{
		c = *base;
		if (c == '-' || c == '+' || is_space(c))
			return (0);
		++base;
	}
	return (1);
}

int		is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *(charset++))
			return (1);
	}
	return (0);
}

#endif
