//만들 함수: ft_strjoin, ft_strlen
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str) {
	int ret = 0;
	for (; str[ret]; ++ret);
	return (ret);
}

char *ft_strjoin(char *str1, char *str2) {
	char *ret;
	int tot_len = ft_strlen(str1) + ft_strlen(str2);

	if (!(ret = (char *)malloc(sizeof(char) * (tot_len + 1))))
		return (NULL);
	ret[tot_len] = '\0';

	int k = 0;
	for (int i = 0; str1[i]; ++i)
		ret[k++] = str1[i];
	for (int i = 0; str2[i]; ++i)
		ret[k++] = str2[i];
	return (ret);
}

int get_next_line(char **line) {
	int ret = 1;
	char buf[2];
	char *backup = ft_strjoin("", "");

	while (ret > 0 && buf[0] != '\n') {
		ret = read(3, buf, 1);
		buf[1] = '\0';
		if (ret > 0 && buf[0] != '\n') {
			char *new_backup = ft_strjoin(backup, buf);	
			free(backup);
			backup = new_backup;
		}
	}
	*line = backup;
	return (ret);
}
