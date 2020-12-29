CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS	= rcs
RM = rm -f
NAME = libft.a

FUNCS = ft_memset \
		ft_bzero \
		ft_strlen \
		ft_strlcpy \
		ft_strncmp \
		ft_atoi \
		ft_strdup \
		ft_substr \
		ft_split \

SRCS = $(addsuffix .c, $(FUNCS))
OBJS = $(SRCS:.c=.o)

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

all : $(NAME)

clean :
	@$(RM) $(OBJS) $(OBJS_B)

fclean :
	@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
