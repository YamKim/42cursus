#include "cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*ret;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen((char *)s);
	if (start >= (unsigned int)len_s)
		return (ft_strdup(""));
	len = (len > (len_s - start)) ? (len_s - start) : len;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

int		check_is_number_arr(char **nbr_arr)
{
	int	k;
	int	i;

	k = 0;
	while (nbr_arr[k])
	{
		i = 0;
		while (nbr_arr[k][i])
		{
			if (!(nbr_arr[k][i] >= 48 && nbr_arr[k][i] <= 57))
				return (ERR_PARSE);	
			++i;
		}
		++k;
	}
	if (k != 3)
		return (ERR_PARSE);
	return (0);
}

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
