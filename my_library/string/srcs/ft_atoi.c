#include "ft_string.h"

int		ft_atoi(char *str)
{
	unsigned int	ret;
	unsigned int	sign;

	sign = 0;
	while (is_space(*str))
		++str;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			++sign;
		++str;
	}
	ret = 0;
	while (is_numeric(*str))
		ret = ret * 10 + (int)(*(str++) - '0');
	return (sign % 2 == 0 ? ret : -ret);
}
