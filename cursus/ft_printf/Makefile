NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
RM = rm -rf

SRC = ft_printf.c \
	printf_info.c \
	printf_type.c \
	printf_type2.c \
	printf_disp.c \
	printf_disp2.c \
	printf_nbr_set.c \
	printf_calc.c

SRCDIR = ./srcs
INCDIR = ./incs
OBJDIR = ./objs
LIBDIR = ./libft
LIBFT = ./libft/libft.a

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
