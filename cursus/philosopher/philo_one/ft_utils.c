#include "philo.h"

int		ft_atoi(const char *nptr)
{
	long long	ret;
	int			sign;

	sign = 0;
	while (*nptr == '\f' || *nptr == '\n' || *nptr == '\r'
			|| *nptr == '\t' || *nptr == '\v' || *nptr == ' ')
		++nptr;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			++sign;
		++nptr;
	}
	ret = 0;
	while (*nptr >= 48 && *nptr <= 57)
		ret = ret * 10 + (long long)(*(nptr++) - '0');
	ret = sign % 2 == 0 ? ret : -ret;
	return ((int)ret);
}
