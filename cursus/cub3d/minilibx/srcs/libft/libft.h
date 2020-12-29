/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 06:54:07 by yekim             #+#    #+#             */
/*   Updated: 2020/12/29 10:15:59 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#if 0
# include <time.h>

# define TEXTURE_ANI_NUMBER 5

typedef struct		s_tex
{
	void			*ptr;
	int				*data;
	int				w;
	int				h;
}					t_tex;

typedef struct		s_vecd
{
	double			x;
	double			y;
}					t_vecd;

typedef struct		s_ani
{
	int				upflag;
	int				idx;
	t_tex			tex[TEXTURE_ANI_NUMBER];
}					t_ani;

typedef struct		s_tic
{
	time_t			beg;
	time_t			end;
}					t_tic;

typedef struct		s_clk
{
	clock_t			beg;
	clock_t			end;
}					t_clk;

typedef struct		s_spr
{
	t_vecd			pos;
	int				tex_nbr;
	t_clk			clk;
	t_tex			*tex;
	t_ani			ani;
}					t_spr;

typedef struct		s_lst
{
	t_spr			spr;
	struct s_lst	*next;
}					t_lst;
#endif

void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
int			ft_atoi(const char *nptr);
char		**ft_split(char const *s, char c, int *wc);
char		*ft_strdup(const char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#if 0
t_lst		*lst_new_spr(t_spr spr);
t_lst		*lst_last(t_lst *lst);
void		lst_add_back(t_lst **lst, t_lst *new_lst);
t_lst		*lst_get_idx(t_lst *lst, int idx);
void		lst_del_idx(t_lst **lst, int idx);
void		lst_clear(t_lst **lst);
#endif
