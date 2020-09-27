#include "ft_string.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	n += 1;
	while ((*s1 || *s2) && --n)
	{
		if (*s1 != *s2)
			break ;
		++s1;
		++s2;
	}
	if (!n)
		return (0);
	return ((int)(*s1 - *s2));
}
