#include <unistd.h>

void set_used(int *used, char *str) {
	for (int i = 0; str[i]; ++i) {
		used[(int)str[i]] = 1;
	}
} 


int main(int argc, char **argv) {
	if (argc == 3) {
		int used_argv1[256];
		int used_argv2[256];
		set_used(used_argv1, argv[1]);
		set_used(used_argv2, argv[2]);
		for (int i = 0; argv[1][i]; ++i) {
			if (used_argv1[(int)argv[1][i]] == 1
				&& used_argv2[(int)argv[1][i]]) {
				write(1, &(argv[1][i]), 1);
				used_argv1[(int)argv[1][i]]++;
			}
		}
	}
	write(1, "\n", 1);	
	return (0);
}
