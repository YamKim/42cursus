#include "ft_file_IO.h"

int	my_fgetc(int *fd)
{
	char	buf;

	if (0 < read(*fd, &buf, sizeof(char)))
		return (buf);
	return (EOF);
}
