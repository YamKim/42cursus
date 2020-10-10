/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 08:15:09 by yekim             #+#    #+#             */
/*   Updated: 2020/10/10 11:24:39 by yekim            ###   ########.fr       */
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

int	get_next_line(int fd, char **line)
{
	static char	*backup;
	char		buf[BUFFER_SIZE];
	char		*next_line;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);

	printf("Call Backup: %s\n", backup);
	// 다음 라인을 찾을 때까지는 뒤에 내용 덧붙이기
	while ((next_line = ft_strchr(backup, '\n')) == 0)
	{
		// 덧붙이는 알고리즘 넣기
		if (read(fd, buf, BUFFER_SIZE) > 0)
		{
			printf("read file==================\n");
			backup = buf;
			break ;
		}
		return (-1);
	}

	// 다음 라인을 찾았다면, 분리해서 line에 값 넣기
	return (split_lines(line, &backup));
}
