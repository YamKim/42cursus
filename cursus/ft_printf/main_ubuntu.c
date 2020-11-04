#include "./incs/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <wchar.h>

void s_test(void);

int main(void) {
	s_test();

	return (0);
}

void s_test(void) {
	int result_r;
	int result_f;
	char *s = "42Seoul";
	printf("For velog\n");
	printf("case1\n");
	result_f = ft_printf("-->|%3s|<--\n", s);
	result_r =    printf("-->|%3s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case2\n");
	result_f = ft_printf("-->|%10s|<--\n", s);
	result_r =    printf("-->|%10s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case3\n");
	result_f = ft_printf("-->|%.4s|<--\n", s);
	result_r =    printf("-->|%.4s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case4\n");
	result_f = ft_printf("-->|%3.4s|<--\n", s);
	result_r =    printf("-->|%3.4s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case5\n");
	result_f = ft_printf("-->|%7.4s|<--\n", s);
	result_r =    printf("-->|%7.4s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case6\n");
	result_f = ft_printf("-->|%.9s|<--\n", s);
	result_r =    printf("-->|%.9s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case7\n");
	result_f = ft_printf("-->|%7.9s|<--\n", s);
	result_r =    printf("-->|%7.9s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("case8\n");
	result_f = ft_printf("-->|%10.9s|<--\n", s);
	result_r =    printf("-->|%10.9s|<--\n", s);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
}
