CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
AR		= ar
RANLIB	= ranlib
RM		= rm -f

TARGET = libstring.a

SRCS_DIR = ./
SRCS = find_idx.c \
 ft_atoi.c \
 ft_atoi_base.c \
 ft_convert_base.c \
 ft_putchar.c \
 ft_putnbr.c \
 ft_putstr.c \
 ft_split.c \
 ft_strcat.c \
 ft_strcmp.c \
 ft_strcpy.c \
 ft_strdup.c \
 ft_strlcat.c \
 ft_strlcpy.c \
 ft_strlen.c \
 ft_strncat.c \
 ft_strncmp.c \
 ft_strncpy.c \
 ft_strstr.c \
 ft_strstr_idx.c \
 is_numeric.c \
 is_space.c \
 strdup_slice.c

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
