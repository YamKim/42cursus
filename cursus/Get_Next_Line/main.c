#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "get_next_line.h"

int main(void) {
	int fd;
	if ((fd = open("test.txt", O_RDONLY)) <= 0)
		return (-1);
	char *line;
	for (int i = 0; i < 2; ++i) {
		if (get_next_line(fd, &line) == -1) 
			printf("gnl failuare\n");
		printf("gnl result: %s\n===========================\n", line);
	}
	return (0);
}
