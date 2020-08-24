#ifndef FT_STRIHG_H
# define FT_STINRG_H

#include <unistd.h>
#include <stdlib.h>

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

/* check string */
int	is_space(char c)
{
	if (c == '\f' || c == '\n' || c == '\r'
			|| c == '\t' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_uniq_str(char *str)
{
	char	*tmp;

	while (*str)
	{
		tmp = str + 1;
		while (*tmp)
		{
			if (*tmp == *str)
				return (0);
			++tmp;
		}
		++str;
		tmp = str;
	}
	return (1);
}

int	check_base(char *base)
{
	char	c;

	if (!base[0] || !base[1])
		return (0);
	if(!is_uniq_str(base))
		return (0);
	while (*base)
	{
		c = *base;
		if (c == '-' || c == '+' || is_space(c))
			return (0);
		++base;
	}
	return (1);
}

/* find string */
int		find_idx(char *str, char c)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		if (*(str++) == c)
			return (ret);	
		++ret;
	}
	return (-1);
}

char	*ft_strstr(char *str, char *to_find)
{
	while (*str)
	{
		if (!ft_strncmp(str, to_find, ft_strlen(to_find)))
			return (str);
		++str;
	}	
	return (NULL);	
}


/* technic string to deal with numeric*/
int		ft_atoi(char *str)
{
	unsigned int	ret;
	unsigned int	sign;

	sign = 0;
	while (is_space(*str))
		++str;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			++sign;
		++str;
	}
	ret = 0;
	while (is_numeric(*str))
		ret = ret * 10 + (int)(*(str++) - '0');
	return (sign % 2 == 0 ? ret : -ret);
}

int		ft_atoi_base(char *nbr, char *base)
{
	unsigned int	ret;
	unsigned int	sign;
	unsigned int	base_type;
	int				add;

	base_type = ft_strlen(base);
	if (!check_base(base))
		return (0);
	while (is_space(*nbr))
		++nbr;
	sign = 0;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			++sign;
		++nbr;
	}
	ret = 0;
	while ((add = find_idx(base, *nbr)) != -1)
	{
		ret = ret * base_type + add;
		++nbr;
	}
	return (sign % 2 != 0 ? -ret : ret);
}

unsigned int	cnt_digits(unsigned int nbr, int type)
{
	unsigned int	ret;

	ret = 0;
	while (nbr)
	{
		nbr /= type;
		ret++;
	}
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*ret;
	int				from;
	unsigned int	nbr_tmp;
	unsigned int	size;
	int				type;
	
	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	from = ft_atoi_base(nbr, base_from);
	type = ft_strlen(base_to);
	if (from < 0)
	{
		nbr_tmp = -from;
		size = cnt_digits(nbr_tmp, type) + 1;
		if (!(ret = (char *)malloc(sizeof(char) * size)))
			return (NULL);
		ret[0] = '-';
	}
	else
	{
		nbr_tmp = from;
		size = cnt_digits(nbr_tmp, type);
		if (!(ret = (char *)malloc(sizeof(char) * size)))
			return (NULL);
	}
	ret[size--] = '\0';
	while (nbr_tmp)
	{
		ret[size--] = base_to[nbr_tmp % type];
		nbr_tmp /= type;
	}
	return (ret);
}

/* split string */
int		is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *(charset++))
			return (1);
	}
	return (0);
}

// use double pointer to save the position of single pointer
int		word_handle(char **str, char *charset, char **ft_sp, int idx)
{
	char	*get_word(char *str, char *charset);
	int		ret;

	ret = 0;
	while (**str)
	{
		while (**str && is_charset(**str, charset))
			++(*str);
		if (**str && !is_charset(**str, charset))
		{
			// when 'idx' is greater or equal with 0, fill the word
			if (idx >= 0)
				ft_sp[idx] = get_word(*str, charset);
			// when 'idx' is -1 -> count word
			else
				++ret;
		}
		while (**str && !is_charset(**str, charset))
			++(*str);	
		if (idx >= 0)
			break;
	}
	return (ret);
}

char	*get_word(char *str, char *charset)
{
	int		idx;
	int		size;
	char	*ret;

	size = 0;
	while (str[size] && !is_charset(str[size], charset))
		++size;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	idx = -1;
	while (++idx < size)
		ret[idx] = str[idx];
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		size;
	int		idx;
	char	*str_tmp1;
	char	*str_tmp2;
		
	str_tmp1 = str;
	size = word_handle(&str_tmp1, charset, 0, -1);
	if (!(ret = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	ret[size] = NULL;
	idx = 0;
	str_tmp2 = str;
	while (idx < size)
		word_handle(&str_tmp2, charset, ret, idx++);
	return (ret);
}

#endif
