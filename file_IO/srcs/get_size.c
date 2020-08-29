#include "ft_file_IO.h"

int		get_size(char *target)
{
	int	fd;
	int	size;

	size = 0;
	if (0 < (fd = open(target, O_RDONLY)))
	{
		while (0 < my_fgetc(&fd))
			++size;
	}
	else
		return (-1);
	return (size);
}
