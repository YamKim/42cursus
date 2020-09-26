#include "ft_file_IO.h"

void	ft_putnbr_fd(int nbr, int fd)
{
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
