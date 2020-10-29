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
	while (get_next_line(fd, &line) > 0)
	{
		printf("gnl res: %s\n", line);
		free(line);
	}
	free(line);
	printf("gnl finished\n");
	printf("stop to leaking check\n");
#if 0
	while (1)
	{}
#endif
	return (0);
}
