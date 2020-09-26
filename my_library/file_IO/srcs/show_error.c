#include "ft_file_IO.h"

void	show_error(char *exe, char *file_name)
{
	my_puterr(basename(exe));
	my_puterr(": ");
	my_puterr(file_name);
	my_puterr(": ");
	my_puterr(strerror(errno));
	my_puterr("\n");
}
