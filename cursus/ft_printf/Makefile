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

SRCDIR = srcs
INCDIR = incs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft all
	cp ./libft/libft.a $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $^
	ranlib $(NAME)

$(OBJS): $(SRCS)
	@mkdir -p objs
	@$(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C ./libft clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(OBJDIR)

re: fclean all
