#include "ft_string.h"

char	*ft_strncpy(char *dst, char *src, unsigned int n)
{
	char	*ret;

	ret = dst;
	n = n + 1;
	while (*src && --n)
		*(dst++) = *(src++);
	while (n && --n)
		*(dst++) = '\0';
	return (ret);
}
