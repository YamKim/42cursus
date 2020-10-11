/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 08:15:09 by yekim             #+#    #+#             */
/*   Updated: 2020/10/11 08:55:23 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> /////////////

int	split_lines(char **line, char **backup)
{
	char *next_line;

	if ((next_line = ft_strchr(*backup, (int)'\n')) != NULL)
	{
		if (!(*line = (char *)malloc(sizeof(char) * (next_line - *backup + 1))))
			return (-1);
		ft_strlcpy(*line, *backup, next_line - *backup + 1);
		*backup = next_line + 1; // next addr of \n
		printf("backup: %s\n", *backup);
	}
	return (0);	
}

int	keep_bufs(char **backup, const char *buf, ssize_t read_size)
{
	size_t	len_backup;
	size_t	len_buf;
	size_t	len_total;
	size_t	idx;
	char	*new_backup;

	len_backup = ft_strlen(*backup);
	len_total = len_backup + read_size + 1;
	if (!(new_backup = (char *)malloc(sizeof(char) * len_total)))
		return (-1);
	idx = ft_strlcpy(new_backup, buf, len_total);
	ft_strlcpy(new_backup + idx, buf, len_total); 		
	free(*backup);
	*backup = new_backup;	
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*backup;
	char		buf[BUFFER_SIZE];
	char		*next_line;
	ssize_t		read_size;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);

	printf("Call Backup: %s\n", backup);
	// 다음 라인을 찾을 때까지는 뒤에 내용 덧붙이기
	while ((next_line = ft_strchr(backup, '\n')) == 0)
	{
		// 덧붙이는 알고리즘 넣기
		while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			printf("read file==================\n");
			break ;
		}
		return (-1);
	}

	// 다음 라인을 찾았다면, 분리해서 line에 값 넣기
	return (split_lines(line, &backup));
}
