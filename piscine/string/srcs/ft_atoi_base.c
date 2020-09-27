#include "ft_string.h"

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

int	ft_atoi_base(char *nbr, char *base)
{
	unsigned int	ret;
	unsigned int	sign;
	unsigned int	base_type;
	int				add;

	if (!check_base(base))
		return (0);
	base_type = ft_strlen(base);
	while (is_space(*nbr))
		++nbr;
	sign = 0;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			++sign;
		++nbr;
	}
	ret = 0;
	while ((add = find_idx(base, nbr[0])) != -1)
	{
		ret = ret * base_type + add;
		++nbr;
	}
	return (sign % 2 != 0 ? -ret : ret);
}
