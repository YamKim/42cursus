#include <stdio.h>

extern int test(int a, int b);
extern int factorial(int n);

int main(void) {
#if 0
	int a  = 5;
	int b  = 20;
	printf("ret: %d\n", test(a, b));
#endif
	printf("ret: %d\n", factorial(5));

}
