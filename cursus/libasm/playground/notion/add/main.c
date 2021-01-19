#include <stdio.h>

#if 0
int mul(int nbr1, int nbr2) {
	return (nbr1 * nbr2);
}
#endif

extern int mul(int nbr1, int nbr2);

int main(void) {
	int a = 4;
	int b = 2;
	printf("result: %d\n", mul(a, b));
	
	return (0);
}
