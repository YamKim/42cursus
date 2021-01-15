#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	int ret;
	char *line;
	if ((fd = open("test/test.txt",O_RDONLY)) < 0)
	{
		printf("No file\n");
		return (0);
	}
	while ((ret = get_next_line(&line)) > 0)
	{
		printf("ret : %d line : %s\n",ret,line);
		free(line);
		line = 0;
	}
	printf("ret : %d line : %s\n",ret,line);
	free(line);
	line = 0;
	close(fd);
	return (0);
}
