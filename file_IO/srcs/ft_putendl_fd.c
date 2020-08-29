#include "ft_file_IO.h"

void	ft_putendl_fd(char *s, int fd)
{
	void	ft_putchar_fd(char c, int fd);
	void	ft_putstr_fd(char *s, int fd);

	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
