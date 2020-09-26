#ifndef FT_STRIHG_H
# define FT_STINRG_H

# include <unistd.h>
# include <stdlib.h>

/* basic */
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*strdup_slice(char *src, int beg, int end);

/* copy */
char			*ft_strcpy(char *dst, char *src);
char			*ft_strncpy(char *dst, char *src, unsigned int n);
unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size);

/* compare */
int	ft_strcmp(char *s1, char *s2);
int	ft_strncmp(char *s1, char *s2, unsigned int n);

/* concat */
char			*ft_strcat(char *dst, char *src);
char			*ft_strncat(char *dst, char *src, unsigned int nb);
unsigned int	ft_strlcat(char *dst, char *src, unsigned int size);

/* check */
int	is_space(char c);
int	is_numeric(char c);

/*===============================================
Number
===============================================*/
void	ft_putnbr(int nbr);
int		ft_atoi(char *str);
int		find_idx(char *str, char c);

/* ft_atoi_base */
int	is_uniq_str(char *str);
int	check_base(char *base);
int	ft_atoi_base(char *nbr, char *base);

/* ft_convert_base */
unsigned int	cnt_digits(unsigned int nbr, int type);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);

/*===============================================
Technic
===============================================*/
/* ft_strstr */
char	*ft_strstr(char *str, char *to_find);
int		ft_strstr_idx(char *str, char *to_find);

/* ft_split */
int		is_charset(char c, char *charset);
int		handle_word(char **str, char *charset, char **ft_sp, int k);
char	**ft_split(char *str, char *charset);

#endif
