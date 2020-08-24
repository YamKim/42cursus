#ifndef FT_STRING_BASIC_H
# define FT_STRING_BASIC_H

# include <unistd.h>
# include <stdlib.h>

/* print string */
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

/* copy string */
char	*ft_strcpy(char *dst, char *src);
char	*ft_strncpy(char *dst, char *src, unsigned int n);
unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size);

/* compare string */
int	ft_strcmp(char *s1, char *s2);
int	ft_strncmp(char *s1, char *s2, unsigned int n);

/* concat string */
char	*ft_strcat(char *dst, char *src);
char	*ft_strncat(char *dst, char *src, unsigned int nb);
unsigned int	ft_strlcat(char *dst, char *src, unsigned int size);

#endif
