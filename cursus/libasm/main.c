#include "./incs/libasm.h"

#include <stdio.h>
#include <string.h>

#define	FT_STRLEN(str)\
		printf("length of [%s]: %lu\n", str, ft_strlen(str));
#define FT_STRCPY(str1, str2)\
		printf("src: %s, dest: %s\n", str2, ft_strcpy(str1, str2));
#define FT_STRCMP(str1, str2)\
		printf("compare [%s], [%s]\n", str1, str2);\
		printf("result of ft_cmp %d\n", ft_strcmp(str1, str2));
#define FT_WRITE(fd, str)\
		printf("result of ft_write: %ld\n", ft_write(fd, str, ft_strlen(str)));\
		printf("error number: %d\n", errno);\
		printf("%s\n", strerror(errno));
#define FT_READ(fd)\
		char buf[50];\
		printf("result of ft_read: %ld\n", ft_read(fd, buf, 5));\
		printf("buf: %s\n", buf); 
#define FT_STRDUP(str)\
		printf("src: %s, dest: %s\n", str, ft_strdup(str));


#define STRCMP(str1, str2)\
		printf("compare [%s], [%s]\n", str1, str2);\
		printf("result of cmp %d\n", strcmp(str1, str2));
#define STRCPY(str1, str2)\
		printf("src: %s, dest: %s\n", str2, strcpy(str1, str2));

int main(void)
{
	//char dest[100];
	//char *src = "abcdefasdkfjlsadjf";

	//FT_STRDUP(src);
//	STRCPY(dest, src);
//	FT_STRCPY(dest, src);
//	STRCMP("efg", "efg");
//	FT_STRCMP("abcd", "efg");
//	FT_STRCMP("abcd", "abcd");
//	FT_STRCMP("", "abcd");
//	FT_STRCMP("abcd", "");
	//FT_STRLEN("abcdefghijklmn\n");
	FT_WRITE(-1, "abced\n");
	//FT_READ();
	return (0);
}
