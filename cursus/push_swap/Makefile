NAME = libpushswap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
RM = rm -rf

FUNC = ft_swap_one \
	ft_swap_both \
	ft_push_one \
	ft_push_both \
	ft_rotate_one \
	ft_rotate_both \
	is_more_than_one_elem \
	print_list \
	
SRCDIR = ./srcs
INCDIR = ./incs
OBJDIR = ./objs
LIBDIR = ./libft
LIBFT  = ./libft/libft.a

SRC  = $(addsuffix .c, $(FUNC))
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBDIR) all
	@cp $(LIBFT) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $^
	@ranlib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

clean:
	@$(RM) $(OBJDIR)
	@$(MAKE) -C $(LIBDIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
