#include <stdio.h>

#if 0
int ft_strlen(char *base) {
	int ret = 0;
	while (*base) {
		++ret;
		base = base + 1;
	}
	return (ret);
}

int get_add_nbr(char *base, char c) {
	int ret = 0;
	while (base[ret]) {
		if (base[ret] == c)
			break;
		++ret;
	}
	return (ret);
}

int ft_atoi_base(char *nbr, char *base) {
	int ret = 0;
	int sign = 0;
	int base_type = ft_strlen(base);
	if (*nbr == '-') {
		++sign;
		nbr = nbr + 1;
	}
	while (*nbr) {
		int add = get_add_nbr(base, *nbr);
		ret = ret * base_type + add;
		nbr = nbr + 1;
	}
	if (sign)
		return (-ret);
	return (ret);
}
#endif

#if 1
extern int ft_atoi_base(char *nbr, char *base);
#endif
int main(void) {
	//unsigned int a = -123;
	//printf("result: %u\n", a);
	//printf("result: %d\n", ft_atoi_base(nbr, "0123456789"));
	printf("result: %d\n", ft_atoi_base("101", "0123456789abcdef"));
	printf("result: %d\n", ft_atoi_base("-101", "0123456789abcdef"));
	return (0);
}
