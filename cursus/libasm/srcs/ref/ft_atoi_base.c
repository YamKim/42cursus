int ft_strlen(char *str) {
	int ret = 0;
	while (str[ret])
		++ret;
	return (ret);
}

int is_space(char c) {
	if (c != 32)
		return (0);
	if (c > 9 && c < 13)
		return (0);
	return (1);
}

int	is_uniq_str(char *str)
{
	while (*str)
	{
		char *tmp = str + 1;
		while (*tmp)
		{
			if (*tmp == *str)
				return (0);
			tmp = tmp + 1;
		}
		str = str + 1;
	}
	return (1);
}

int	is_base(char *base)
{
	char	c;

	if (!base[0] || !base[1])
		return (0);
	if(!is_uniq_str(base))
		return (0);
	while (*base)
	{
		c = *base;
		if (c == '-')
			return (0);
		if (c == '+')
			return (0);
		if (is_space(c))
			return (0);
		base = base + 1;
	}
	return (1);
}

int get_add_nbr(char *base, char c) {
	int ret = 0;
	while (base[ret]) {
		if (base[ret] == c)
			break;
		++ret;
	}
	return (ret);
}

int	ft_atoi_base(char *nbr, char *base)
{
	if (!is_base(base))
		return (0);
	unsigned int base_type = ft_strlen(base);
	// space는 무시하기
	while (is_space(*nbr))
		nbr = nbr + 1;
	unsigned int sign = 0;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			++sign;
		nbr = nbr + 1;
	}
	unsigned int ret = 0;
	int add;
	while (*nbr) {
		if ((add = get_add_nbr(base, *nbr)) >= base_type)
			break ;
		ret = ret * base_type + add;
		nbr = nbr + 1;
	}
	if (sign % 2 != 0)
		ret = -ret;
	return (ret);
}
