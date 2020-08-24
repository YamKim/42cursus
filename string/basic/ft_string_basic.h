#ifndef FT_STRING_BASIC_H
# define FT_STRING_BASIC_H

# include <unistd.h>
# include <stdlib.h>

/* print string */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

int		ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (*(str++))
		++ret;
	return (ret);
}

/* copy string */
char	*ft_strcpy(char *dst, char *src)
{
	char	*ret;

	ret = dst;
	while (*src)
		*(dst++) = *(src++);
	*dst = *src;
	return (ret);
}

char	*ft_strncpy(char *dst, char *src, unsigned int n)
{
	char	*ret;

	ret = dst;
	n = n + 1;
	while (*src && --n)
		*(dst++) = *(src++);
	while (n && --n)
		*(dst++) = '\0';
	return (ret);
}

unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	unsigned int	ret;

	ret = 0;
	while (*src && --size)
	{
		*(dst++) = *(src++);
		++ret;
	}
	*dst = '\0';
	while (*(src++))
		++ret;
	return (ret);
}

/* compare string */
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			break ;
		++s1;
		++s2;
	}
	return ((int)(*s1 - *s2));
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	n += 1;
	while ((*s1 || *s2) && --n)
	{
		if (*s1 != *s2)
			break ;
		++s1;
		++s2;
	}
	if (!n)
		return (0);
	return ((int)(*s1 - *s2));
}

/* concat string */
char	*ft_strcat(char *dst, char *src)
{
	char	*ret;

	ret = dst;
	while (*dst)
		++dst;
	while (*src)
		*(dst++) = *(src++);
	*dst = '\0';
	return (ret);
}

char	*ft_strncat(char *dst, char *src, unsigned int nb)
{
	char	*ret;

	ret = dst;
	while (*dst)
		++dst;
	nb += 1;
	while (*src && --nb > 0)
		*(dst++) = *(src++);
	*dst = '\0';
	return (ret);
}

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	src_len;
	unsigned int	itr;

	len = 0;
	src_len = ft_strlen(src);
	while (*dst)
	{
		++dst;
		++len;
	}
	if (size <= len)
		return (src_len + size);
	itr = size - len + 1;
	while (*src && --itr)
		*(dst++)  = *(src++);
	*dst = '\0';
	return (src_len + len);
}

#endif
