CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
AR		= ar
RANLIB	= ranlib
RM		= rm -f

TARGET = libfileio.a

SRCS_DIR = ./
SRCS = ft_putchar_fd.c \
 ft_putendl_fd.c \
 my_puterr.c \
 ft_putnbr_fd.c \
 ft_putstr_fd.c \
 get_size.c \
 my_fgetc.c \
 my_fgets.c \
 my_gets.c \
 my_input.c \
 my_puterror.c \
 show_error.c

OBJS = $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(TARGET) : $(OBJS)
	$(AR) rcv $@ $^
	$(RANLIB) $@

all : $(TARGET)

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(TARGET)

re : fclean all

.PHONY: all clean fclean re
