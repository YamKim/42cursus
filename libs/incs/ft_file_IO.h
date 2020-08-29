#ifndef FT_FILE_IO_H
# define FT_FILE_IO_H

# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>
# include <stdio.h>
# include "../../string/srcs/ft_string.h"

# define STD_IN     (0)
# define STD_OUT    (1)
# define STD_ERR    (2)

# define BUF_SIZE	4096

/* read */
int		my_fgetc(int *fd);
char	*my_fgets(char *str, int size, int *fd);
int		get_size(char *target);
char	*my_input();
char	*my_gets(int *fd, int size);

/* write */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nbr, int fd);

/* Command Line Interface */
void	my_puterr(char *str);
void	show_error(char *exe, char *file_name);

#endif
