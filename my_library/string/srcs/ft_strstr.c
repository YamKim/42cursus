#include "ft_string.h"

char	*ft_strstr(char *str, char *to_find)
{
	while (*str)
	{
		if (!ft_strncmp(str, to_find, ft_strlen(to_find)))
			return (str);
		++str;
	}
	return (NULL);
}
