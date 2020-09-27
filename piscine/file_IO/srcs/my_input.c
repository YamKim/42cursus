#include "ft_file_IO.h"

char	*my_input(void)
{
	char	*pre;
	char	*cur;
	int		size;
	char	buf;

	size = 1;
	if (!(pre = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	pre[size] = '\0';
	if (!(0 < read(STD_IN, pre, sizeof(char))))
		return (NULL);
	while (0 < read(STD_IN, &buf, sizeof(char)))
	{
		if (buf == 10)
			break ;
		++size;
		if (!(cur = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		ft_strlcpy(cur, pre, size + 1);
		cur[size - 1] = buf;
		cur[size] = '\0';
		free(pre);
		pre = cur;
	}
	return (cur);
}
