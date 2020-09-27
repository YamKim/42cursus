#include "ft_file_IO.h"

char	*my_gets(int *fd, int size)
{
	char	*ret;
	int		idx;
	char	buf;

	if (!(ret = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ret[size] = '\0';
	idx = 0;
	while ((0 < (buf = my_fgetc(fd))) && (size - idx))
	{
		if (buf == 10)
			break ;
		ret[idx++] = buf;
	}
	return (ret);
}
