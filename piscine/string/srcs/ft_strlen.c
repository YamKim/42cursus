#include "ft_string.h"

int		ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (*(str++))
		++ret;
	return (ret);
}
