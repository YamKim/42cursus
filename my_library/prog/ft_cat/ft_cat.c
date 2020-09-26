#include "ft_cat.h"

int		read_data(int fd)
{
	char	buf_in;

	while (0 < (buf_in = my_fgetc(&fd)))
	{
		ft_putchar(buf_in);
	}
	close(fd);
	return (1);
}

void	stdin_mode(void)
{
	read_data(STD_IN);
}

int		ft_cat(int argc, char **argv)
{
	int	idx;
	int	fd;

	idx = 0;
	while (++idx < argc)
	{
		if (0 < (fd = open(argv[idx], O_RDONLY)))
		{
			if (!(read_data(fd)))
				return (-1);
		}
		else
		{
			show_error(argv[0], argv[idx]);
			return (-1);
		}
	}
	return (1);
}
