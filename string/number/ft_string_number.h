#ifndef FT_STRING_NUMBER_H
# define FT_STRING_NUMBER_H

# include <unistd.h>
# include <stdlib.h>
# include "../basic/ft_string_basic.h"
# include "../util/ft_string_check.h"
# include "../technic/ft_string_technic.h"

/* technic string to deal with numeric*/
void			ft_putnbr(int nbr)
{
	int				sign;
	unsigned int	nbr_tmp;

	if (!nbr)
		return ;
	sign = nbr < 0 ? 1 : 0;
	if (sign)
	{
		ft_putchar('-');
		nbr_tmp = -nbr;
	}
	else
		nbr_tmp = nbr;
	ft_putnbr(nbr_tmp / 10);	
	ft_putchar(nbr_tmp % 10 + '0');
}

int				ft_atoi(char *str)
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

int				ft_atoi_base(char *nbr, char *base)
{
	unsigned int	ret;
	unsigned int	sign;
	unsigned int	base_type;
	int				add;

	base_type = ft_strlen(base);
	if (!check_base(base))
		return (0);
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
	while ((add = find_idx(base, *nbr)) != -1)
	{
		ret = ret * base_type + add;
		++nbr;
	}
	return (sign % 2 != 0 ? -ret : ret);
}

unsigned int	cnt_digits(unsigned int nbr, int type)
{
	unsigned int	ret;

	ret = 0;
	while (nbr)
	{
		nbr /= type;
		ret++;
	}
	return (ret);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*ret;
	int				from;
	unsigned int	nbr_tmp;
	unsigned int	size;
	int				type;
	
	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	from = ft_atoi_base(nbr, base_from);
	type = ft_strlen(base_to);
	if (from < 0)
	{
		nbr_tmp = -from;
		size = cnt_digits(nbr_tmp, type) + 1;
		if (!(ret = (char *)malloc(sizeof(char) * size)))
			return (NULL);
		ret[0] = '-';
	}
	else
	{
		nbr_tmp = from;
		size = cnt_digits(nbr_tmp, type);
		if (!(ret = (char *)malloc(sizeof(char) * size)))
			return (NULL);
	}
	ret[size--] = '\0';
	while (nbr_tmp)
	{
		ret[size--] = base_to[nbr_tmp % type];
		nbr_tmp /= type;
	}
	return (ret);
}

#endif
