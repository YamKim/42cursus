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
	int	res;
	res = get_next_line(fd, &line);
	printf("res: %d\n", res);
	free(line);
	return (0);
}
