#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef struct	s_info
{
	int			width;
	int			prec;
	int			space_len;
	int			pad_len;
	int			width_flag;
	int			prec_flag;
	char		conv;
}				t_info;

int ft_isdigit(char c) {
	return (c >= '0' && c <= '9');
}

void get_width_info(const char **format, t_info *info) {
	info->width = 0;
	while (ft_isdigit(**format)) {
		info->width_flag = 1;
		info->width = info->width * 10 + (**format - '0');
		++(*format);
	}
}

void get_prec_info(const char **format, t_info *info) {
	info->prec = 0;
	if (**format == '.') {
		++(*format);
		while (ft_isdigit(**format)) {
			info->prec_flag = 1;
			info->prec = info->prec * 10 + (**format - '0');
			++(*format);
		}
	}
}

void get_info(const char **format, t_info *info) {
	info->width_flag = 0;
	info->prec_flag = 0;
	get_width_info(format, info);
	get_prec_info(format, info);
	info->conv = **format;
}

int ft_strlen(char *str) {
	int ret = 0;
	for (; str[ret]; ++ret);
	return (ret);
}

char *ft_itoa(int nbr, char *base) {
	char *ret;
	
	unsigned int tmp_nbr;
	tmp_nbr = nbr < 0 ? -nbr : nbr;
	int ret_size = nbr < 0 ? 1 : 0;

	int base_len = ft_strlen(base);
	while (tmp_nbr) {
		++ret_size;	
		tmp_nbr /= base_len;
	}
	if (nbr == 0)
		ret_size = 1;

	if (!(ret = (char *)malloc(sizeof(char) * (ret_size + 1))))
		return (NULL);
	ret[ret_size--] = '\0';

	tmp_nbr = nbr < 0 ? -nbr : nbr;
	while (tmp_nbr) {
		ret[ret_size--] = base[tmp_nbr % base_len];
		tmp_nbr /= base_len;
	}
	ret[0] = nbr == 0 ? '0' : ret[0];
	return (ret);
}

char *ft_itoa_x(unsigned int nbr, char *base) {
	char *ret;
	
	unsigned int tmp_nbr = nbr;
	int ret_size = 0;

	int base_len = ft_strlen(base);
	while (tmp_nbr) {
		++ret_size;	
		tmp_nbr /= base_len;
	}
	if (nbr == 0)
		ret_size = 1;

	if (!(ret = (char *)malloc(sizeof(char) * (ret_size + 1))))
		return (NULL);
	ret[ret_size--] = '\0';

	tmp_nbr = nbr;
	while (tmp_nbr) {
		ret[ret_size--] = base[tmp_nbr % base_len];
		tmp_nbr /= base_len;
	}
	ret[0] = nbr == 0 ? '0' : ret[0];
	return (ret);
}

int zero_case(t_info *info) {
	int ret = 0;
	if (info->prec == 0) {
		for (int i = 0; i < info->width; ++i)
			ret += write(1, " ", 1);
	}
	else if (info->width == 0) {
		for (int i = 0; i < info->prec; ++i)
			ret += write(1, "0", 1);
	}
	return (ret);
}

int ft_write_d(t_info *info, int nbr) {
	int ret = 0;
	if (nbr == 0 && (info->prec_flag && info->width_flag) \
		&& (info->prec == 0 || info ->width == 0))
		return (zero_case(info));

	char *nbr_str = ft_itoa(nbr, "0123456789");
	int nbr_str_len = ft_strlen(nbr_str);
	
	// prec이 width 보다 우선
	if (nbr >= 0) {
		info->pad_len = info->prec > nbr_str_len ? info->prec - nbr_str_len : 0;
		int tmp_len = info->pad_len + nbr_str_len;
		info->space_len = info->width > tmp_len ? info->width - tmp_len : 0; 
		for (int i = 0; i < info->space_len; ++i)
			ret += write(1, " ", 1);
		for (int i = 0; i < info->pad_len; ++i)
			ret += write(1, "0", 1);
		ret += write(1, nbr_str, nbr_str_len);
	}
	else {
		nbr_str_len -= 1;
		info->pad_len = info->prec > nbr_str_len ? info->prec - nbr_str_len : 0;
		int tmp_len = info->pad_len + nbr_str_len + 1;
		info->space_len = info->width > tmp_len ? info->width - tmp_len : 0; 
		for (int i = 0; i < info->space_len; ++i)
			ret += write(1, " ", 1);
		ret += write(1, "-", 1);
		for (int i = 0; i < info->pad_len; ++i)
			ret += write(1, "0", 1);
		ret += write(1, &nbr_str[1], nbr_str_len);
	}
	free(nbr_str);
	return (ret);
}

int ft_write_x(t_info *info, unsigned int nbr) {
	int ret = 0;
	if (nbr == 0 && (info->prec_flag && info->width_flag) \
		&& (info->prec == 0 || info ->width == 0))
		return (zero_case(info));

	char *nbr_str = ft_itoa_x(nbr, "0123456789abcdef");
	int nbr_str_len = ft_strlen(nbr_str);
	
	// prec이 width 보다 우선
	if (nbr >= 0) {
		info->pad_len = info->prec > nbr_str_len ? info->prec - nbr_str_len : 0;
		int tmp_len = info->pad_len + nbr_str_len;
		info->space_len = info->width > tmp_len ? info->width - tmp_len : 0; 
		for (int i = 0; i < info->space_len; ++i)
			ret += write(1, " ", 1);
		for (int i = 0; i < info->pad_len; ++i)
			ret += write(1, "0", 1);
		ret += write(1, nbr_str, nbr_str_len);
	}
	else {
		nbr_str_len -= 1;
		info->pad_len = info->prec > nbr_str_len ? info->prec - nbr_str_len : 0;
		int tmp_len = info->pad_len + nbr_str_len + 1;
		info->space_len = info->width > tmp_len ? info->width - tmp_len : 0; 
		for (int i = 0; i < info->space_len; ++i)
			ret += write(1, " ", 1);
		ret += write(1, "-", 1);
		for (int i = 0; i < info->pad_len; ++i)
			ret += write(1, "0", 1);
		ret += write(1, &nbr_str[1], nbr_str_len);
	}
	free(nbr_str);
	return (ret);
}

int ft_write_s(t_info *info, char *str) {
	int ret = 0;
	int str_len = ft_strlen(str);

	int disp_len = str_len;
	if (info->prec_flag)
		disp_len = str_len > info->prec ? info->prec : str_len;
	info->space_len = info->width > disp_len ? info->width - disp_len : 0;

	for (int i = 0; i < info->space_len; ++i)
		ret += write(1, " ", 1);
	for (int i = 0; i < disp_len; ++i)
		ret += write(1, &str[i], 1);

	return (ret);
}

int ft_write(t_info *info, va_list args) {
	int ret = 0;
	if (info->conv == 'd')
		ret = ft_write_d(info, va_arg(args, int));
	if (info->conv == 's')
		ret = ft_write_s(info, va_arg(args, char *));
	if (info->conv == 'x')
		ret = ft_write_x(info, va_arg(args, unsigned int));
	return (ret);
}

int ft_printf(const char *str, ...) {
	va_list args;
	int	ret;

	ret = 0;
	va_start(args, str);
	while (*str) {
		if (*str != '%')
			ret += write(1, &(*str++), 1);
		else {
			t_info info;
			++str; // point after %
			get_info(&str, &info);
			ret += ft_write(&info, args);
			++str; // point after conversion
		}
	}
	va_end(args);
	return (ret);
}
