#include <stdio.h>
#include <stdlib.h>

extern void make_pointer(int **nbr);

int main(void) {
	int *nbr;
	make_pointer(&nbr);
	printf("nbr[0]: %d, nbr[1]: %d\n", nbr[0], nbr[1]);

	return (0);
}

#if 0
void make_pointer(int **nbr) {
	*nbr = (int *)malloc(sizeof(int) * 2);
	(*nbr)[0] = 4;
	(*nbr)[1] = 2;
}
#endif
