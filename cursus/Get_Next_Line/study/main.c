#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(void) {
	int fd;
	char buf1[BUFF_SIZE];
	char buf2[BUFF_SIZE];
	size_t read_size = 7;

	char *file_name = "./test.txt";
	if (0 >= (fd = open(file_name, O_RDONLY))) {
		printf("failure opening file\n");
		return (0);
	}
	read(fd, buf1, sizeof(char) * read_size);
	write(1, buf1, sizeof(char) * read_size);
	printf("\nNEXT=======================\n");
	read(fd, buf2, sizeof(char) * read_size);
	write(1, buf2, sizeof(char) * read_size);
	close(fd);
	return (0);
}
