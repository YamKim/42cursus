#include "./incs/libasm.h"

#define DEBUG_FT_STRLEN		0
#define DEBUG_FT_STRCPY		0
#define DEBUG_FT_STRCMP		0
#define DEBUG_FT_WRITE		0
#define DEBUG_FT_READ		0
#define DEBUG_FT_STRDUP		1

#if DEBUG_FT_STRLEN
#define	FT_STRLEN(str)\
		printf("length of [%s]: [%lu]\n", str, ft_strlen(str));
int main(void) {
	FT_STRLEN("Hello World");
	FT_STRLEN("");
	FT_STRLEN("Hello 42 Seoullllllllllllllllllllllllllllllllllllll");
	return (0);
}
#endif

#if DEBUG_FT_STRCPY
#define FT_STRCPY(str1, str2)\
		printf("copy [%s] <- [%s]\n", str2, ft_strcpy(str1, str2));
int main(void) {
	char a[10];
	FT_STRCPY(a, "42");
	char b[10] = "42 Seoul";
	FT_STRCPY(b, "");
	char c[20] = "42";
	FT_STRCPY(c, "42 Seoul");
	char d[100] = "52 lllllllllllllllllllllllllllllllllllll";
	FT_STRCPY(d, "42");
	char e[10] = "52";
	FT_STRCPY(e, "42 Seoullllllllllllllllllllllllllllllll");
	return (0);
}
#endif

#if DEBUG_FT_STRCMP
#define FT_STRCMP(str1, str2)\
		printf("compare [%s] , [%s]\n", str1, str2);\
		printf("result of ft_cmp: [%d]\n", ft_strcmp(str1, str2));
int main(void) {
	FT_STRCMP("", "");
	FT_STRCMP("", "4242");
	FT_STRCMP("4242", "");
	FT_STRCMP("42", "42");
	FT_STRCMP("421", "42");
	FT_STRCMP("42", "421");
	return (0);
}
#endif

#if DEBUG_FT_WRITE
#define FT_WRITE(fd, str)\
		printf("result of ft_write: [%ld]\n",\
				ft_write(fd, str, ft_strlen(str))); \
		printf("error number: [%d]\n", errno);\
		printf("[%s]\n", strerror(errno));

int main(void) {
	FT_WRITE(1, "Hello 42 Seoul!\n");
	printf("=========================\n");

	int fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
	FT_WRITE(fd, "Hello 42 Seoul!\n");
	printf("=========================\n");
	close(fd);

	FT_WRITE(-1, "Hello 42 Seoul!\n");
	printf("=========================\n");
}
#endif

#if DEBUG_FT_READ
#define FT_READ(fd, buf)\
		printf("result of ft_read: [%ld]\n", ft_read(fd, buf, 5));\
		printf("error number: [%d]\n", errno);\
		printf("[%s]\n", strerror(errno));\
		printf("buf: [%s]\n", buf); 

int main(void) {
	char buf1[50];
	FT_READ(0, buf1);
	printf("=========================\n");

	char buf2[50];
	int fd = open("test.txt", O_RDONLY);
	FT_READ(fd, buf2);
	printf("=========================\n");
	close(fd);

	char buf3[50];
	FT_READ(-1, buf3);
	printf("=========================\n");
	return (0);
}
#endif

#if DEBUG_FT_STRDUP
#define FT_STRDUP(str)\
		printf("[%s] -> [%s]\n", str, ft_strdup(str));

int main(void) {
	FT_STRDUP("");
	FT_STRDUP("42 Seoul");
	FT_STRDUP("42 Seoulllllllllllllllllllllllllllllllllllllll");
	return (0);
}
#endif
