#include <stdio.h>

#if 0
int ft_strlen(char *str) {
	int ret = 0;
	while (*str) {
		++ret;
		str = str + 1;
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

int get_nbr(char *nbr, char *base) {
	int ret = 0;
	int base_type = ft_strlen(base);
	while (*nbr) {
		int add = get_add_nbr(base, *nbr);
		ret = ret * base_type + add;
		nbr = nbr + 1;
	}
	return (ret);
}
#endif

//extern int get_add_nbr(char *base, char c);
extern int get_nbr(char *nbr, char *base);

int main(void) {
	//printf("res: %d\n", get_add_nbr("12345678", '4'));
	printf("res: %d\n", get_nbr("21", "0123456789"));

	return (0);
}
