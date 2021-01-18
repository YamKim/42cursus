#ifndef _LIBASM_H
# define _LIBASM_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(
		char * dst,
		const char * src);
int		ft_strcmp(
		const char *s1,
		const char *s2);

ssize_t	ft_write(
		int fildes,
		void const *buf,
		size_t nbyte);

ssize_t ft_read(
		int fildes,
		void *buf,
		size_t nbyte);

char	*ft_strdup(const char *s1);

int		ft_atoi_base(
		char *nbr,
		char *base);

#endif
