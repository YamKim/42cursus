#include <stdio.h>
#include "get_next_line.h"

char *mini_keep_bufs(char *str) {
	static char *backup;
	char *new_backup;
	// new_backup의 길이를 구하기
	size_t len = ft_strlen(backup) + ft_strlen(str);

	if (!(new_backup = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);

	// new_backup에 backup 값과 새로운 값 복사
	size_t idx = ft_strlcpy(new_backup, backup, len + 1);
	ft_strlcpy(new_backup + idx, str, len + 1);	

	// backup이 new_backup을 가리키도록 설정
	free(backup);
	backup = new_backup;
	return (backup);
}

int main(void) {
	printf("%s\n", mini_keep_bufs("Hello 42"));
	printf("%s\n", mini_keep_bufs(" world, "));
	printf("%s\n", mini_keep_bufs("yekim!"));
	return (0);
}
