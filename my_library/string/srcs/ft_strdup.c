#include "ft_string.h"

char	*ft_strdup(char *src)
{
	char	*ret;
	int		idx;
	int		len;

	len = ft_strlen(src);
	ret = (char *)malloc(sizeof(char) * len);
	idx = 0;
	while (src[idx] != '\0')
	{
		ret[idx] = src[idx];
		++idx;
	}
	ret[idx] = '\0';
	return (ret);
}
