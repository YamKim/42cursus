#include <stdio.h>

#if 0
int	get_sign(char **pre) {
	char *pos = *pre;
	int ret = 0;
	while (1) {
		if (!(*pos == '-' || *pos == '+'))
			break;
		++ret;
		pos = pos + 1;
	}
	*pre = pos;
	return (ret);
}
#endif

extern int	get_sign(char **pre);

int main(void) {
	char *part = "- +";
	printf("result: %d\n", get_sign(&part));
	printf("curr_pos: %c\n", *part);

	return (0);
}
