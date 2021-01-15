#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// 
	char *b = (char *)malloc(2);
	b[0] = 1;
	b[1] = 1;
	int *a = (int *)b;
	printf("result: %d\n", *a);

	return (0);
}


