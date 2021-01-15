#include <stdio.h>
#include <stdlib.h>

#if 0
void get_data(int *buf, int val) {
	buf[0] = val;
	buf[1] = val;
}
#endif

extern void get_data(int *buf, int *val);
int main(void) {
	int *a;
	int a_size = 2;
	a = (int *)malloc(sizeof(int) * a_size);
	if (a == NULL)
		return (0);
	int val = 2;
	get_data(a, &val);
	for (int i = 0; i < a_size; ++i) {
		printf("%p\n", &(a[i]));
		printf("%d\n", a[i]);
	}

	return (0);
}
