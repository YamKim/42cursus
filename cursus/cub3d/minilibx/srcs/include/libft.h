/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 06:54:07 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 10:37:48 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include "./utils.h"
# include <unistd.h>
# include <stdlib.h>

void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
int			ft_atoi(const char *nptr);
char		**ft_split(char const *s, char c, int *wc);
char		*ft_strdup(const char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);

t_lst		*lst_new_spr(t_spr spr);
t_lst		*lst_last(t_lst *lst);
void		lst_add_back(t_lst **lst, t_lst *new_lst);
t_lst		*lst_get_idx(t_lst *lst, int idx);
void		lst_del_idx(t_lst **lst, int idx);
void		lst_clear(t_lst **lst);
#endif
