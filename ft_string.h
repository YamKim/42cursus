#ifndef FT_STRIHG_H
# define FT_STINRG_H

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	int				sign;
	unsigned int	nbr_tmp;

	if (!nbr)
		return ;
	sign = nbr < 0 ? 1 : 0;
	if (sign)
	{
		ft_putchar('-');
		nbr_tmp = -nbr;
	}
	else
		nbr_tmp = nbr;
	ft_putnbr(nbr_tmp / 10);	
	ft_putchar(nbr_tmp % 10 + '0');
}

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		write(1, &str[idx++], 1);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx])
	{
		dst[idx] = src[idx];
		++idx;
	}
	dst[idx] = src[idx];
	return (dst);
}

char	*ft_strncpy(char *dst, char *src, unsigned int n)
{
	unsigned int idx;

	idx = 0;
	while (src[idx] && idx < n)
	{
		dst[idx] = src[idx];
		++idx;
	}
	while (idx < n)
	{
		dst[idx] = '\0';
		++idx;
	}
	return (dst);
}

#endif
