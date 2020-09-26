#include "ft_string.h"

char	*ft_strncat(char *dst, char *src, unsigned int nb)
{
	char	*ret;

	ret = dst;
	while (*dst)
		++dst;
	nb += 1;
	while (*src && --nb > 0)
		*(dst++) = *(src++);
	*dst = '\0';
	return (ret);
}
