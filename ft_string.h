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

int		ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (*(str++))
		++ret;
	return (ret);
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

unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	unsigned int	ret;
	unsigned int	size_tmp;

	ret = 0;
	size_tmp = (int)size;
	while (src[ret] && ret < size_tmp - 1)
	{
		dst[ret] = src[ret];
		++ret;
	}
	dst[ret] = '\0';
	while (src[ret] != '\0')
		++ret;
	return (ret);
}

#include <stdio.h>
int	ft_strcmp(char *s1, char *s2)
{
	while (*(s1++) || *(s2++))
	{
		if (*s1 != *s2)
			break ;
	}
	return ((int)(*s1 - *s2));
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while ((*(s1++) || *(s2++)) && (n > 0))
	{
		if (*s1 != *s2)
			break ;
		--n;
	}
	if (n == 0)
		return (0);
	printf("s1: %c, s2: %c\n", *s1, *s2);
	return ((int)(*s1 - *s2));
}

#endif
