#ifndef _LIBASM_H
# define _LIBASM_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;


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

int		ft_list_size(t_list *begin_list);

void	ft_list_push_front(
		t_list **begin_list, void *data);

void	ft_list_remove_if(
		t_list **begin_list,
		void *data_ref,
		int (*cmp)());

t_list	*ft_list_sort(
		t_list *lst,
		int (*cmp)());

int		ft_atoi_base(
		char *nbr,
		char *base);

#endif
