#include "ft_string.h"

int		ft_strstr_idx(char *str, char *to_find)
{
	int	ft_strlen(char *str);
	int	ft_strncmp(char *s1, char *s2, unsigned int n);
	int	ret;

	ret = 0;
	while (*str)
	{
		if (!ft_strncmp(str, to_find, ft_strlen(to_find)))
			return (ret);	
		++ret;
		++str;
	}
	return (-1);
}
