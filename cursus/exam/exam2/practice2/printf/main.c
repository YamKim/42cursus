#include <stdio.h>
#include <limits.h>

extern int ft_printf(const char *str, ...);

int main() {
	int i;

#if 0
	i = printf("%d\n", 0);
	printf("1. ret : %d\n", i);
	i = ft_printf("%d\n", 0);
	ft_printf("1. ret : %d\n", i);
#endif

#if 0
	printf("[%%.d]:");
	i = printf("%.d\n", 0);
	printf("ret : %d\n", i);
	printf("[%%0.d]:");
	i = printf("%0.d\n", 0);
	printf("ret : %d\n", i);
	printf("[%%.0d]:");
	i = printf("%.0d\n", 0);
	printf("ret : %d\n", i);
	printf("[%%0.0d]:");
	i = printf("%0.0d\n", 0);
	printf("ret : %d\n", i);
	printf("[%%5.0d]:");
	i = printf("%5.0d\n", 0);
	printf("ret : %d\n", i);
	printf("[%%5.d]:");
	i = printf("%5.d\n", 0);
	printf("ret : %d\n", i);
	printf("[%%0.5d]:");
	i = printf("%0.5d\n", 0);
	printf("ret : %d\n", i);
	printf("[%%.5d]:");
	i = printf("%.5d\n", 0);
	printf("ret : %d\n", i);
	ft_printf("[%%.d]:");
	i = ft_printf("%.d\n", 0);
	ft_printf("ret : %d\n", i);
	ft_printf("[%%0.d]:");
	i = ft_printf("%0.d\n", 0);
	ft_printf("ret : %d\n", i);
	ft_printf("[%%.0d]:");
	i = ft_printf("%.0d\n", 0);
	ft_printf("ret : %d\n", i);
	ft_printf("[%%0.0d]:");
	i = ft_printf("%0.0d\n", 0);
	ft_printf("ret : %d\n", i);
	ft_printf("[%%5.0d]:");
	i = ft_printf("%5.0d\n", 0);
	ft_printf("ret : %d\n", i);
	ft_printf("[%%5.d]:");
	i = ft_printf("%5.d\n", 0);
	ft_printf("ret : %d\n", i);
	ft_printf("[%%0.5d]:");
	i = ft_printf("%0.5d\n", 0);
	ft_printf("ret : %d\n", i);
	ft_printf("[%%.5d]:");
	i = ft_printf("%.5d\n", 0);
	ft_printf("ret : %d\n", i);
#endif

#if 0
	i = printf("%.5d\n", -24);
	printf("ret : %d\n", i);
	i = ft_printf("%.5d\n", -24);
	ft_printf("ret : %d\n", i);
	i = printf("%5d\n", -24);
	printf("ret : %d\n", i);
	i = ft_printf("%5d\n", -24);
	ft_printf("ret : %d\n", i);
	i = printf("%30.20d\n", INT_MIN);
	printf("26. ret : %d\n", i);
	i = ft_printf("%30.20d\n", INT_MIN);
	ft_printf("26. ret : %d\n", i);
	i = printf("%.30d\n", INT_MIN);
	printf("33. ret : %d\n", i);
	i = ft_printf("%.30d\n", INT_MIN);
	ft_printf("33. ret : %d\n", i);
	i = printf("%d\n", 0);
	printf("1. ret : %d\n", i);
	i = ft_printf("%d\n", 0);
	ft_printf("1. ret : %d\n", i);
	i = printf("%0.0d\n", 0);
	printf("22. ret : %d\n", i);
	i = ft_printf("%0.0d\n", 0);
	ft_printf("22. ret : %d\n", i);
	i = printf("%0.30d\n", INT_MIN);
	printf("31. ret : %d\n", i);
	i = ft_printf("%0.30d\n", INT_MIN);
	ft_printf("31. ret : %d\n", i);
	i = printf("%50.0d\n", 0);
	printf("25. ret : %d\n", i);
	i = ft_printf("%50.0d\n", 0);
	ft_printf("25. ret : %d\n", i);
	i = printf("%.0d\n", 0);
	printf("25. ret : %d\n", i);
	i = ft_printf("%.0d\n", 0);
	ft_printf("25. ret : %d\n", i);
	i = printf("%.20d\n", 0);
	printf("25. ret : %d\n", i);
	i = ft_printf("%.20d\n", 0);
	ft_printf("25. ret : %d\n", i);
	i = printf("%50.d\n", 0);
	printf("25. ret : %d\n", i);
	i = ft_printf("%50.d\n", 0);
	ft_printf("25. ret : %d\n", i);
	i = printf("ceci est un %s, ok ?\n", "test");
	printf("ret : %d\n", i);
	i = ft_printf("ceci est un %s, ok ?\n", "test");
	ft_printf("ret : %d\n", i);
	i = printf("%10.0s\n", "test");
	printf("ret : %d\n", i);
	i = ft_printf("%10.0s\n", "test");
	ft_printf("ret : %d\n", i);
	printf("ret : %d\n", i);
#endif
	i = printf("%x\n", -5);
	printf("ret : %d\n", i);
	i = ft_printf("%x\n", -5);
	ft_printf("ret : %d\n", i);
	return (0);
}
