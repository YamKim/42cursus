#include <stdio.h>

int neg_ret(int nbr) {
	if (nbr >= 0)
		return (-nbr);
	return (nbr);
}

int main(void) {
	printf("result: %d\n", neg_ret(-20));
	return (0);
}
