#include <stdio.h>

#if 0
static int ft_strlen(char *str) {
	int ret = 0;
	while (*str) {
		str = str + 1;
		ret = ret + 1;
	}
	return (ret);
}
#endif

extern int ft_strlen(char *str);

int main(void) {
	printf("result: %d\n", ft_strlen("abcdef"));
	return (0);
}
