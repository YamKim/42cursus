#include <unistd.h>

static void	set_used_char(int *used, char *str) {
	for (int i = 0; str[i]; ++i) {
		used[(int)str[i]] = 1;
	}
}

int main(int argc, char **argv) {
	if (argc == 3) {
		int used_in_argv1[256];
		int used_in_argv2[256];
		set_used_char(used_in_argv1, argv[1]);
		set_used_char(used_in_argv2, argv[2]);
		for (int i = 0; argv[1][i]; ++i) {
			char print_char = argv[1][i];
			if (used_in_argv1[(int)print_char] == 1
				&& used_in_argv2[(int)print_char]) {
				write(1, &print_char, 1);
				++used_in_argv1[(int)print_char];
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
