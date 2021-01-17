#include <stdio.h>

#if 0
int ft_atoi(char *nbr) {
	int ret = 0;
	int sign = 0;
	if (*nbr == '-') {
		++sign;
		nbr = nbr + 1;
	}
	while (*nbr) {
		ret = ret * 10 + *nbr - '0';
		nbr = nbr + 1;
	}
	if (sign)
		return (-ret);
	return (ret);
}
#endif
extern int ft_atoi(char *nbr);

int main(void) {
	//unsigned int a = -123;
	//printf("result: %u\n", a);
	printf("result: %d\n", ft_atoi("-5"));
	return (0);
}
