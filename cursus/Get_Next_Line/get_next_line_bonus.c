/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 06:46:44 by yekim             #+#    #+#             */
/*   Updated: 2020/11/02 13:36:21 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	split_lines(char **line, char **backup, char *next_line)
{
	char	*new_backup;
	size_t	len_total;

	len_total = next_line - *backup;
	if (!(*line = (char *)malloc(sizeof(char) * (len_total + 1))))
		return (-1);
	ft_strlcpy(*line, *backup, len_total + 1);
	if (ft_strlen(next_line + 1) == 0)
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	new_backup = ft_strdup(next_line + 1);
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
	len_total = len_backup + read_size;
	if (!(new_backup = (char *)malloc(sizeof(char) * (len_total + 1))))
		return (-1);
	idx = ft_strlcpy(new_backup, *backup, len_total + 1);
	ft_strlcpy(new_backup + idx, buf, len_total + 1);
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

int			get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX + 1];
	char		*buf;
	char		*next_line;
	ssize_t		read_size;

	if (fd < 0 || fd > OPEN_MAX || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((next_line = ft_strchr(backup[fd], (int)'\n')) == NULL)
	{
		if ((read_size = read(fd, buf, BUFFER_SIZE)) <= 0)
		{
			free(buf);
			return (return_all(line, &(backup[fd]), read_size));
		}
		buf[read_size] = '\0';
		if (keep_bufs(&(backup[fd]), buf, read_size) == -1)
		{
			free(buf);
			return (-1);
		}
	}
	free(buf);
	return (split_lines(line, &(backup[fd]), next_line));
}
