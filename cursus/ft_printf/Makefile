NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -rf

SRC = ft_printf.c \
		printf_info.c \
		printf_conv.c \
		printf_conv2.c \
		printf_put.c \
		printf_base.c \
		printf_calc.c \

LIBSRC = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

SRCDIR = srcs
INCDIR = incs
OBJDIR = objs
LIBDIR = libft

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
LIBSRC = $(addprefix $(LIBDIR)/, $(LIBSRC))

HEADER = -I $(INCDIR)

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
LIBOBJS = $(LIBSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBOBJ)
	@$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p objs
	@$(CC) $(CFLAGS) -c $< $(HEADER) -o $@ 

$(LIBOBJ): %.o: %.c
	@$(CC) $(CFLAG) -c $< $(HEADER) -o $@

clean:
	@$(RM) $(OBJS) $(LIBOBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -r $(OBJDIR)

re: fclean all
