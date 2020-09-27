#include "ft_file_IO.h"

char	*my_fgets(char *str, int size, int *fd)
{
	int		idx;
	char	buf;

	idx = 0;
	while ((0 < (buf = my_fgetc(fd))) && (size - idx))
		str[idx++] = buf;
	str[idx] = '\0';
	return (str);
}
