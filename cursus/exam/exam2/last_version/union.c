#include <unistd.h>

int main(int argc, char **argv) {
	if (argc == 3) {
		int used[256];
		for (int i = 0; i < 256; ++i)
			used[i] = 0;
		for (int i = 0; argv[1][i]; ++i)
		{
			if (used[(int)argv[1][i]] == 0) {
				write(1, &argv[1][i], 1);
				used[(int)argv[1][i]] = 1;
			}
		}
		for (int i = 0; argv[2][i]; ++i)
		{
			if (used[(int)argv[2][i]] == 0) {
				write(1, &argv[2][i], 1);
				used[(int)argv[2][i]] = 1;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
