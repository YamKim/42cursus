#include "ft_string.h"

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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
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
