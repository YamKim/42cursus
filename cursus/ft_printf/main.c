#include <stdio.h>
#include "ft_printf.h"

int main(void) {
	//char *format = ft_strdup("Hello %d %s!");	
	//simple_printf(format, 42, "World");
#if 0
	printf("printf result\n");
	int ret1 = printf("%-51cHiHi\n", 'a');
	printf("ret1: %d\n", ret1);
#endif
#if 0
	printf("printf result\n");
	char *a;
	int ret1 = printf("%s", a);
	printf("ret1: %d\n", ret1);
#endif
#if 0
	printf("ft_printf result\n");
	int ret2 = ft_printf("%-51cHiHi\n", 'a');
	printf("ret2: %d\n", ret2);
#endif
#if 1
	ft_printf("ft_printf result\n");
	char *b;
	int ret2 = printf("%s", b);
	printf("ret2: %d\n", ret2);
#endif

	return (0);
}
