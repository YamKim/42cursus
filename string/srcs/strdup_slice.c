#include "ft_string.h"

char	*strdup_slice(char *src, int beg, int end)
{
	int		ft_strlen(char *str);
	char	*ret;
	int		idx;
	int		len;
	int		range;

	len = ft_strlen(src);
	range = end - beg + 1;
	if (range > len)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * range + 1);
	idx = 0;
	while (idx < range)
	{
		ret[idx] = src[beg + idx];
		++idx;
	}
	ret[idx] = '\0';
	return (ret);
}
