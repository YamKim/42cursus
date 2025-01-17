/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 04:36:22 by dhaouhao          #+#    #+#             */
/*   Updated: 2021/01/11 09:50:22 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

#define DEC "0123456789"
#define HEX "0123456789abcdef"
#define FLG "dsx"

typedef struct	s_parse
{
	size_t		is_width;
	size_t		width;
	size_t		is_prec;
	size_t		prec;
	char		type;
}				t_parse;

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	if (!(dest = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s || !(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start < ft_strlen(s))
		while (i < len && s[i + start])
		{
			substr[i] = s[i + start];
			i++;
		}
	substr[i] = '\0';
	return (substr);
}

size_t	ft_putchar(char c)
{
	return ((size_t)write(1, &c, sizeof(char)));
}

size_t	ft_putstr(char *s)
{
	size_t	ret;

	ret = 0;
	if (s)
		while (*s)
			ret += ft_putchar(*(s++));
	return (ret);
}

int		ft_is_flag(char c, const char *flags)
{
	while (*flags)
		if (*(flags++) == c)
			return (1);
	return (0);
}

char	*ft_ulltoa_base(unsigned long long nbr, char *base)
{
	char	*str;
	int		nbr_final[20];
	int		len;
	int		i;
	int		base_len;

	len = (nbr == 0) ? 1 : 0;
	nbr_final[0] = 0;
	base_len = ft_strlen(base);
	while (nbr)
	{
		nbr_final[len++] = nbr % base_len;
		nbr /= base_len;
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (--len >= 0)
		str[i++] = base[nbr_final[len]];
	str[i] = '\0';
	return (str);
}

char	*ft_fill_width_or_prec(char *str, size_t *parsed_value)
{
	if (ft_is_flag(*str, DEC))
		while (*str >= '0' && *str <= '9')
			*parsed_value = (*parsed_value * 10) + (*(str++) - '0');
	return (str);
}

void	ft_fill_struct(t_parse *parsed, char *str)
{
	char	*tmp;

	tmp = str;
	parsed->is_width = 0;
	parsed->width = 0;
	parsed->is_prec = 0;
	parsed->prec = 0;
	parsed->type = 0;
	while (*str)
	{
		if (ft_is_flag(*str, DEC) && *str != '0' && (parsed->is_width = 1))
			str = ft_fill_width_or_prec(str, &parsed->width);
		if (*str == '.' && (parsed->is_prec = 1))
			str = ft_fill_width_or_prec(++str, &parsed->prec);
		if (ft_is_flag(*str, FLG))
			parsed->type = *str;
		str++;
	}
	free(tmp);
}

size_t	ft_write_s(t_parse *parsed, char *tmp)
{
	char	*new_str;
	char	*str;
	size_t	len;
	size_t	ret;

	new_str = (tmp == NULL) ? ft_strdup("(null)") : ft_strdup(tmp);
	if (parsed->is_prec && parsed->prec < ft_strlen(new_str))
		str = ft_substr(new_str, 0, parsed->prec);
	else
		str = ft_strdup(new_str);
	len = ft_strlen(str);
	ret = 0;
	while (parsed->width-- > len)
		ret += ft_putchar(' ');
	ret += ft_putstr(str);
	free(new_str);
	free(str);
	return (ret);
}

size_t	ft_fill_0_dx(size_t is_neg, char *tmp, size_t size)
{
	size_t	ret;

	ret = (is_neg) ? ft_putchar('-') : 0;
	while (size > 0 && size-- > 0)
		ret += ft_putchar('0');
	ret += ft_putstr(tmp);
	return (ret);
}

size_t	ft_write_dx(t_parse *parsed, long nbr)
{
	char	*tmp;
	size_t	ret;
	size_t	is_neg;
	size_t	len;
	size_t	prec_is_0;

	is_neg = (nbr < 0) ? 1 : 0;
	tmp = ft_ulltoa_base(is_neg ? -nbr : nbr, parsed->type == 'x' ? HEX : DEC);
	len = ft_strlen(tmp);
	ret = 0;
	if ((!parsed->is_width && !parsed->is_prec) ||
	(!(parsed->prec >= len || parsed->width >= len + is_neg) && nbr != 0) ||
	(parsed->prec >= len || parsed->width >= len + is_neg))
	{
		prec_is_0 = (parsed->is_prec && !parsed->prec && !nbr) ? 1 : 0;
		parsed->prec = (parsed->prec < len) ? len : parsed->prec;
		if (parsed->width < parsed->prec + is_neg)
			parsed->width = parsed->prec + is_neg;
		while (parsed->width-- + prec_is_0 > parsed->prec + is_neg)
			ret += ft_putchar(' ');
		ret += (!prec_is_0) ? ft_fill_0_dx(is_neg, tmp, parsed->prec - len) : 0;
	}
	free(tmp);
	return (ret);
}

size_t	ft_write_n_return(char *str, va_list args)
{
	t_parse	parsed;
	size_t	ret;

	ret = 0;
	ft_fill_struct(&parsed, str);
	if (parsed.type == 's')
		ret = ft_write_s(&parsed, va_arg(args, char *));
	else if (parsed.type == 'd')
		ret = ft_write_dx(&parsed, va_arg(args, int));
	else if (parsed.type == 'x')
		ret = ft_write_dx(&parsed, va_arg(args, unsigned int));
	return (ret);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	ret;
	int		i;
	int		j;

	ret = 0;
	va_start(args, str);
	while (*str && ((i = (*str == '%')) || 1))
	{
		while (str[i] && ((*str != '%' && str[i] != '%') ||
		(*str == '%' && !ft_is_flag(str[i], FLG))))
			i++;
		if (*str == '%' && ft_is_flag(str[i], FLG))
			ret += ft_write_n_return(ft_substr(str, 1, ++i - 1), args);
		else if ((j = (*str == '%')) || 1)
			while (j < i)
				ret += ft_putchar(str[j++]);
		str += i;
	}
	va_end(args);
	return ((int)ret);
}

#if 0
int	main(int ac, char **av)
{
	(void)ac;
	ft_printf(" ret : %d", ft_printf(av[1], atoi(av[2])));
	printf("\n");
	printf(" ret : %d", printf(av[1], atoi(av[2])));
	printf("\n\n");
	return (0);
}
#endif

int main()
{

	printf("---------------------d_no_flags-------------------\n");
	//ft_printf(" ret : %d", ft_printf("|%d|", INT_MIN));
	//printf("\n");
	printf(" ret : %d", printf("|%d|", INT_MIN));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%d|", INT_MAX));
	//printf("\n");
	printf(" ret : %d", printf("|%d|", INT_MAX));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%d|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%d|", 0));
	printf("\n\n");

	printf("---------------------d_width-------------------\n");
	//ft_printf(" ret : %d", ft_printf("|%30d|", INT_MIN));
	//printf("\n");
	printf(" ret : %d", printf("|%30d|", INT_MIN));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%3d|", INT_MAX));
	//printf("\n");
	printf(" ret : %d", printf("|%3d|", INT_MAX));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%30d|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%30d|", 0));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%0d|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%0d|", 0));
	printf("\n\n");

	printf("---------------------d_prec-------------------\n");
	//ft_printf(" ret : %d", ft_printf("|%.30d|", INT_MIN));
	//printf("\n");
	printf(" ret : %d", printf("|%.30d|", INT_MIN));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%.3d|", INT_MAX));
	//printf("\n");
	printf(" ret : %d", printf("|%.3d|", INT_MAX));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%.30d|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%.30d|", 0));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%.0d|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%.0d|", 0));
	printf("\n\n");

	printf("---------------------d_width_prec-------------------\n");
	//ft_printf(" ret : %d", ft_printf("|%45.20d|", INT_MIN));
	//printf("\n");
	printf(" ret : %d", printf("|%45.20d|", INT_MIN));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%45.20d|", INT_MAX));
	//printf("\n");
	printf(" ret : %d", printf("|%45.20d|", INT_MAX));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%45.20d|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%45.20d|", 0));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%45.0d|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%45.0d|", 0));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%15.0d|", INT_MAX));
	//printf("\n");
	printf(" ret : %d", printf("|%15.0d|", INT_MAX));
	printf("\n\n");

	printf("---------------------x_no_flags-------------------\n");
	//ft_printf(" ret : %d", ft_printf("|%x|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%x|", 0));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%x|", UINT_MAX));
	//printf("\n");
	printf(" ret : %d", printf("|%x|", UINT_MAX));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%x|", -123));
	//printf("\n");
	printf(" ret : %d", printf("|%x|", -123));
	printf("\n\n");

	printf("---------------------x_width-------------------\n");
	//ft_printf(" ret : %d", ft_printf("|%30x|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%30x|", 0));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%3x|", UINT_MAX));
	//printf("\n");
	printf(" ret : %d", printf("|%3x|", UINT_MAX));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%30x|", -123));
	//printf("\n");
	printf(" ret : %d", printf("|%30x|", -123));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%0x|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%0x|", 0));
	printf("\n\n");


	printf("---------------------x_prec-------------------\n");
	//ft_printf(" ret : %d", ft_printf("|%.30x|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%.30x|", 0));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%.3x|", UINT_MAX));
	//printf("\n");
	printf(" ret : %d", printf("|%.3x|", UINT_MAX));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%.30x|", -123));
	//printf("\n");
	printf(" ret : %d", printf("|%.30x|", -123));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%.x|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%.x|", 0));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%.0x|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%.0x|", 0));
	printf("\n\n");


	printf("---------------------x_width_prec-------------------\n");
	//ft_printf(" ret : %d", ft_printf("|%45.20d|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%45.20d|", 0));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%45.20d|", UINT_MAX));
	//printf("\n");
	printf(" ret : %d", printf("|%45.20d|", UINT_MAX));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%45.20d|", -123));
	//printf("\n");
	printf(" ret : %d", printf("|%45.20d|", -123));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%45.0d|", 0));
	//printf("\n");
	printf(" ret : %d", printf("|%45.0d|", 0));
	printf("\n\n");
	//ft_printf(" ret : %d", ft_printf("|%15.0d|", UINT_MAX));
	//printf("\n");
	printf(" ret : %d", printf("|%15.0d|", UINT_MAX));
	printf("\n\n");


	printf("---------------------s_no_flags-------------------\n");
//	ft_printf(" ret : %d", ft_printf("|%s|", "abcdefghij"));
//	printf("\n");
	printf(" ret : %d", printf("|%s|", "abcdefghij"));
	printf("\n\n");
//	ft_printf(" ret : %d", ft_printf("|%s|", "abcdefghij"));
//	printf("\n");
	printf(" ret : %d", printf("|%s|", "abcdefghij"));
	printf("\n\n");
//	ft_printf(" ret : %d", ft_printf("|%s|", NULL));
//	printf("\n");
	//printf(" ret : %d", printf("|%s|", NULL));
	//printf("\n\n");


	printf("---------------------s_width-------------------\n");
//	ft_printf(" ret : %d", ft_printf("|%30s|", "abcdefghij"));
//	printf("\n");
	printf(" ret : %d", printf("|%30s|", "abcdefghij"));
	printf("\n\n");
//	ft_printf(" ret : %d", ft_printf("|%3s|", "abcdefghij"));
//	printf("\n");
	printf(" ret : %d", printf("|%3s|", "abcdefghij"));
	printf("\n\n");
//	ft_printf(" ret : %d", ft_printf("|%30s|", NULL));
//	printf("\n");
	//printf(" ret : %d", printf("|%30s|", NULL));
	//printf("\n\n");


	printf("---------------------s_prec-------------------\n");
//	ft_printf(" ret : %d", ft_printf("|%.30s|", "abcdefghij"));
//	printf("\n");
	printf(" ret : %d", printf("|%.30s|", "abcdefghij"));
	printf("\n\n");
//	ft_printf(" ret : %d", ft_printf("|%.6s|", "abcdefghij"));
//	printf("\n");
	printf(" ret : %d", printf("|%.6s|", "abcdefghij"));
	printf("\n\n");
//	ft_printf(" ret : %d", ft_printf("|%.30s|", NULL));
//	printf("\n");
	//printf(" ret : %d", printf("|%.30s|", NULL));
	//printf("\n\n");
//	ft_printf(" ret : %d", ft_printf("|%.3s|", NULL));
//	printf("\n");
	//printf(" ret : %d", printf("|%.3s|", NULL));
	//printf("\n\n");
//	ft_printf(" ret : %d", ft_printf("|%.s|", NULL));
//	printf("\n");
	//printf(" ret : %d", printf("|%.s|", NULL));
	//printf("\n\n");

	printf("---------------------s_width_prec-------------------\n");
	ft_printf(" ret : %d", ft_printf("|%45.20s|", "abcdefghij"));
//	printf("\n");
//	printf(" ret : %d", printf("|%45.20s|", "abcdefghij"));
	printf("\n\n");
	ft_printf(" ret : %d", ft_printf("|%45.20s|", "abcdefghij"));
//	printf("\n");
//	printf(" ret : %d", printf("|%45.20s|", "abcdefghij"));
	printf("\n\n");
	ft_printf(" ret : %d", ft_printf("|%45.20s|", NULL));
//	printf("\n");
//	//printf(" ret : %d", printf("|%45.20s|", NULL));
	//printf("\n\n");
	ft_printf(" ret : %d", ft_printf("|%10.2s|", "toto"));
//	printf("\n");
//	printf(" ret : %d", printf("|%10.2s|", "toto"));
	printf("\n\n");
	ft_printf(" ret : %d", ft_printf("|Magic %s is %5d|", "number", 42));
//	printf("\n");
//	printf(" ret : %d", printf("|Magic %s is %5d|", "number", 42));
	printf("\n\n");
	ft_printf(" ret : %d", ft_printf("|Hexadecimal for %d is %x|", 42, 42));
//	printf("\n");
//	printf(" ret : %d", printf("|Hexadecimal for %d is %x|", 42, 42));
	printf("\n\n");



	// ft_printf("|Hexadecimal for is %yyyy|\n");
	// printf("|Hexadecimal for is %yyyy|\n");
	// printf("\n\n");


	printf("---------------------NULL-------------------\n");
	//ft_printf(NULL);
	//printf(NULL);
	printf("\n\n");
	return (0);
}
