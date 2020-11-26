#include "cub3d.h"

static int	ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r'
			|| c == '\t' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(char *nptr)
{
	unsigned int	ret;
	int				sign;

	sign = 0;
	while (ft_isspace(*nptr))
		++nptr;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			++sign;
		++nptr;
	}
	ret = 0;
	while (*nptr >= 48 && *nptr <= 57)
		ret = ret * 10 + (unsigned int)(*(nptr++) - '0');
	if (sign % 2 == 0)
		return ((int)ret);
	return (-ret);
}
