#include <unistd.h>

static void set_used_char(int *used, char *str)
{
	for (int i = 0; str[i]; ++i) {
		char print_char = str[i];
		if (used[(int)print_char] == 0) {
			write(1, &(print_char), 1);
			used[(int)print_char] = 1;
		}
	}
}

int main(int argc, char **argv) {
	if (argc == 3) {
		int used[256];
		set_used_char(used, argv[1]);
		set_used_char(used, argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}
