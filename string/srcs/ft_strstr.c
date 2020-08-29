#include "ft_string.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	ft_strlen(char *str);
	int	ft_strncmp(char *s1, char *s2, unsigned int n);

	while (*str)
	{
		if (!ft_strncmp(str, to_find, ft_strlen(to_find)))
			return (str);
		++str;
	}	
	return (NULL);	
}
