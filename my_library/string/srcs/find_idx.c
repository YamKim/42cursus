#include "ft_string.h"

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
