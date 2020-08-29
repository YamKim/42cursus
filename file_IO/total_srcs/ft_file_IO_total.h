#ifndef FT_FILE_IO_H
# define FT_FILE_IO_H

# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>
# include <stdio.h>
# include "../string/ft_string.h"

# define STD_IN     (0)
# define STD_OUT    (1)
# define STD_ERR    (2)

# define BUF_SIZE	4096

/* read */
int		my_fgetc(int *fd)
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

char	*my_input()
{
	unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size);
	char			*pre;
	char			*cur;
	int				size;
	char			buf;

	size = 1;
	if (!(pre = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	pre[size] = '\0';
	if (!(0 < read(STD_IN, pre, sizeof(char))))
		return (NULL);
	while (0 < read(STD_IN, &buf, sizeof(char)))
	{
		if (buf == 10)
			break ;
		++size;
		if (!(cur = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		ft_strlcpy(cur, pre, size + 1);
		cur[size - 1] = buf;
		cur[size] = '\0';
		free(pre);
		pre = cur;
	}
	return (cur);	
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


/* write */
void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, sizeof(char));
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	void	ft_putchar_fd(char c, int fd);
	void	ft_putstr_fd(char *s, int fd);

	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_putnbr_fd(int nbr, int fd)
{
	void			ft_putchar_fd(char c, int fd);
	int				sign;
	unsigned int	nbr_tmp;

	if (!nbr)
		return ;
	sign = nbr < 0 ? 1 : 0;
	if (sign)
	{
		ft_putchar_fd('-', fd);
		nbr_tmp = -nbr;
	}
	else
		nbr_tmp = nbr;
	ft_putnbr_fd(nbr_tmp / 10, fd);	
	ft_putchar_fd(nbr_tmp % 10 + '0', fd);
}

/* Command Line Interface */
void	my_puterr(char *str)
{
	while (*str)
		write(STD_ERR, str++, 1);
}

void	show_error(char *exe, char *file_name)
{
	my_puterr(basename(exe));
	my_puterr(": ");
	my_puterr(file_name);
	my_puterr(": ");
	my_puterr(strerror(errno));
	my_puterr("\n");
}

#endif
