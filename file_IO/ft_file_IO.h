#ifndef FT_FILE_IO_H
# define FT_FILE_IO_H

# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>
# include "../string/ft_string.h"

# define STD_IN     (0)
# define STD_OUT    (1)
# define STD_ERR    (2)

# define BUF_SIZE	4096

int	my_fgetc(int *fd)
{
	char	buf;

	if (0 < read(*fd, &buf, sizeof(char)))
		return (buf);
	return (EOF);
}

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

int		get_file_size(char *target)
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
			break;
		ret[idx++] = buf;
	}
	return (ret);	
}

void	ft_puterr(char *str)
{
	while (*str)
		write(STD_ERR, str++, 1);
}

void	show_error(char *exe, char *file_name)
{
	ft_puterr(basename(exe));
	ft_puterr(": ");
	ft_puterr(file_name);
	ft_puterr(": ");
	ft_puterr(strerror(errno));
	ft_puterr("\n");
}

int		ft_cat(int argc, char **argv)
{
	int		fd;
	char	data;
	char	str[BUF_SIZE];
	int		size;
	int		file_idx;
	
	if (argc == 1)
	{
		fd = STD_IN;
		while (0 < (data = my_fgetc(&fd)))
			ft_putchar(data);
	}
	file_idx = 0;
	while (++file_idx < argc)
	{
		if (0 > (fd = open(argv[file_idx], O_RDONLY)))
		{
			show_error(argv[0], argv[file_idx]);
			return (-1);
		}
		size = get_file_size(argv[file_idx]);
		ft_putstr(my_fgets(str, size, &fd));
		close(fd);
	}
	return (1);
}

#if 0
char	*ft_getstr(int *fd)
{
   	char	buf[BUF_SIZE];
	int		fd;

	if (0 < (fd = open(file_name, O_RDONLY)))
	{
		while (0 < read(fd, buf, 1))
			ft_putchar(*buf);
	}
	else
		return (-1);
	close(fd);
	return (1);
}

int	open_file(char * target, int flag)
{
	int	fd;

	if (0 < (fd = open(target, flag)))
		return (-1);	
	return fd;
}
#endif


#endif
