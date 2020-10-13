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

#include  "get_next_line.h"

static int	split_lines(char **line, char **backup, char *next_line)
{
	char	*new_backup;

	if (!(*line = (char *)malloc(sizeof(char) * (next_line - *backup + 1))))
		return (-1);
	ft_strlcpy(*line, *backup, next_line - *backup + 1);
	new_backup = ft_strdup(next_line + 1); 
	if (new_backup[0] == '\0')
	{
		free(new_backup);
		free(*backup);
		new_backup = NULL;
		*backup = NULL;
		return (1);
	}
	free(*backup);
	*backup = new_backup;
	return (1);	
}

static int	keep_bufs(char **backup, const char *buf, ssize_t read_size)
{
	size_t	len_backup;
	size_t	len_total;
	size_t	idx;
	char	*new_backup;

	len_backup = ft_strlen(*backup);
	len_total = len_backup + read_size + 1;
	if (!(new_backup = (char *)malloc(sizeof(char) * len_total)))
		return (-1);
	idx = ft_strlcpy(new_backup, *backup, len_total);
	ft_strlcpy(new_backup + idx, buf, len_total); 		
	free(*backup);
	*backup = new_backup;	
	return (1);
}

static int	return_all(char **line, char **backup, ssize_t read_size)
{
	if (read_size < 0)
		return (-1);
	if (*backup == NULL)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	*line = *backup;
	*backup = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1]; // 뒤에 null 처리해주기. 쓰레기값 들어감.
	char		*next_line;
	ssize_t		read_size;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((next_line = ft_strchr(backup, (int)'\n')) == NULL)
	{
		if ((read_size = read(fd, buf, BUFFER_SIZE)) <= 0)
			return (return_all(line, &backup, read_size));
		buf[read_size] = '\0';
		if (keep_bufs(&backup, buf, read_size) == -1)
			return (-1);
	}
	return (split_lines(line, &backup, next_line));
}
