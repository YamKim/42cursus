#include "ft_file_IO.h"

void	my_puterr(char *str)
{
	while (*str)
		write(STD_ERR, str++, 1);
}
