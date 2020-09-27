#include "ft_string.h"

char	*ft_strcpy(char *dst, char *src)
{
	char	*ret;

	ret = dst;
	while (*src)
		*(dst++) = *(src++);
	*dst = *src;
	return (ret);
}
