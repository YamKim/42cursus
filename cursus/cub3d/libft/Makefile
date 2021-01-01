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
		ft_putnbr \
		ft_putstr \
		ft_putchar \
		lst_new_spr \
		lst_last \
		lst_add_back \
		lst_get_idx \
		lst_del_idx \
		lst_clear

SRCS = $(addsuffix .c, $(FUNCS))
OBJS = $(SRCS:.c=.o)
INCS = -I ../include/

.c.o :
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

all : $(NAME)

clean :
	@$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
