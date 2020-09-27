#include "ft_string.h"

unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	unsigned int	ret;

	ret = 0;
	while (*src && --size)
	{
		*(dst++) = *(src++);
		++ret;
	}
	*dst = '\0';
	while (*(src++))
		++ret;
	return (ret);
}
