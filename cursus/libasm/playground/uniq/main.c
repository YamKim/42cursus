#include <stdio.h>

#if 0
static int uniq(char *str) {
	while (*str) {
		char *tmp = str + 1;
		while (*tmp) {
			if (*tmp == *str)
				return (0);
			tmp = tmp + 1;
		}	
		str = str + 1;
	}
	return (1);
}
#endif
extern int is_uniq(char *str);

int main(void) {
	printf("res: %d\n", is_uniq("01921"));
	printf("res: %d\n", is_uniq("01920"));
	printf("res: %d\n", is_uniq("01924"));
	printf("res: %d\n", is_uniq("019"));

	return (0);
}
