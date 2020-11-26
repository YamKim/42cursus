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

int		check_is_number_arr(char **nbr_arr, int index_num)
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
	if (index_num != 3)
		return (ERR_PARSE);
	return (0);
}

