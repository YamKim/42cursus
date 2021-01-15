#include <stdarg.h>
#include <unistd.h>

typedef struct		s_info
{
	int width;
	int prec;
	char conv;
	int prec_flag;	// %d가 zero case인 경우,
					// %s에서 prec가 있는 경우를 관리하기 위함.
	int	space_len;  // width가 출력문자보다 큰 경우 공백을 위함.
	int	pad_len;	// prec이 출력문자보다 큰 경우 패딩을 위함.
}					t_info;

int ft_isdigit(char c) {
	return (c >= '0' && c <= '9');
}

void get_info(const char **format, t_info *info) {
	info->pad_len = 0;
	info->space_len = 0;
	info->width = 0;
	while (ft_isdigit(**format)) {
		info->width = info->width * 10 + (**format - '0');
		++(*format);
	}
	info->prec = 0;
	info->prec_flag = 0;
	if (**format == '.') {
		info->prec_flag = 1;
		++(*format);
		while (ft_isdigit(**format)) {
			info->prec = info->prec * 10 + (**format - '0');
			++(*format);
		}
	}
	info->conv = **format;
}

void ft_putnbr(unsigned int nbr, char *base, unsigned int base_len) {
	if (nbr >= base_len) {
		ft_putnbr(nbr / base_len, base, base_len);
	}
	char print_nbr = base[(int)nbr % base_len];
	write(1, &print_nbr, 1);
}

int get_nbr_len(unsigned int nbr, int base_len) {
	int ret = 0;
	if (nbr == 0) return (1);
	while (nbr) {
		nbr /= base_len;
		++ret;
	}
	return (ret);
}

// 분석해본 결과, 골치아픈 경우는 va_arg값이 0일 때,
// '.'이 있고(즉, prec_flag가 켜져있고) width나 prec이 0인 경우
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
	int sign = nbr < 0 ? 1 : 0;
	unsigned int print_nbr = sign ? -nbr : nbr;

	int nbr_len = get_nbr_len(print_nbr, 10);

	if (nbr == 0 && info->prec_flag \
		&& (info->prec == 0 || info->width == 0))
		return (zero_case(info));
	// 음수인 경우, 순서: space -> sign -> pad -> number
	if (sign) {
		info->pad_len = info->prec > nbr_len ? info->prec - nbr_len : 0;
		int	tmp_len = info->pad_len + nbr_len + 1;
		// 주의: 부호도 공간을 하나 잡아먹기 때문에 한칸 더 더해줌
		info->space_len = info->width > tmp_len ? info->width - tmp_len : 0;
		for (int i = 0; i < info->space_len; ++i)
			ret += write(1, " ", 1);
		ret += write(1, "-", 1);
		for (int i = 0; i < info->pad_len; ++i)
			ret += write(1, "0", 1);
		ft_putnbr(print_nbr, "0123456789", 10);
		ret += nbr_len;
	}
	// 양수인 경우, 순서: space -> pad -> number
	else {
		info->pad_len = info->prec > nbr_len ? info->prec - nbr_len : 0;
		int	tmp_len = info->pad_len + nbr_len;
		info->space_len = info->width > tmp_len ? info->width - tmp_len : 0;
		for (int i = 0; i < info->space_len; ++i)
			ret += write(1, " ", 1);
		for (int i = 0; i < info->pad_len; ++i)
			ret += write(1, "0", 1);
		ft_putnbr(print_nbr, "0123456789", 10);
		ret += nbr_len;
	}
	return (ret);
}

int ft_strlen(char *str) {
	int ret = 0;
	for (; str[ret]; ++ret);
	return (ret);
}

int ft_write_s(t_info *info, char *str) {
	int ret = 0;
	int str_len = ft_strlen(str);
	int disp_len = str_len;
	// 주의: '.'이 없어도 info->prec은 0이 되므로, 이 경우는 배제
	if (info->prec_flag)
		disp_len = disp_len > info->prec ? info->prec : disp_len;
	info->space_len = info->width > disp_len ? info->width - disp_len : 0; 
	for (int i = 0; i < info->space_len; ++i)
		ret += write(1, " ", 1);
	for (int i = 0; i < disp_len; ++i)
		ret += write(1, &str[i], 1);
	return (ret);
}

// ft_write_d와 완전히 같지만, 음수인 경우 제외
int ft_write_x(t_info *info, unsigned int nbr) {
	int ret = 0;
	int sign = nbr < 0 ? 1 : 0;
	unsigned int print_nbr = sign ? -nbr : nbr;

	int nbr_len = get_nbr_len(print_nbr, 16);

	if (nbr == 0 && info->prec_flag \
		&& (info->prec == 0 || info->width == 0))
		return (zero_case(info));
	info->pad_len = info->prec > nbr_len ? info->prec - nbr_len : 0;
	int	tmp_len = info->pad_len + nbr_len;
	info->space_len = info->width > tmp_len ? info->width - tmp_len : 0;
	for (int i = 0; i < info->space_len; ++i)
		ret += write(1, " ", 1);
	for (int i = 0; i < info->pad_len; ++i)
		ret += write(1, "0", 1);
	ft_putnbr(print_nbr, "0123456789abcdef", 16);
	ret += nbr_len;
	return (ret);
}

int ft_write(t_info *info, va_list args) {
	int ret = 0;
	if (info->conv == 'd')
		ret += ft_write_d(info, va_arg(args, int));
	if (info->conv == 's')
		ret += ft_write_s(info, va_arg(args, char *));
	if (info->conv == 'x')
		ret += ft_write_x(info, va_arg(args, unsigned int));
	
	return (ret);
}

int ft_printf(const char *format, ...) {
	va_list args;
	int ret = 0;

	va_start(args, format);
	while (*format) {
		if (*format != '%')
			ret += write(1, format++, 1);
		else {
			++format;
			t_info info;
			get_info(&format, &info);
			++format;
			ret += ft_write(&info, args);
		}
	}
    va_end(args);
	return (ret);
}
