NAME		= libasm.a
NAME_TEST	= test
ACC			= nasm
AFLAGS		= -f macho64
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= rcs
RM			= rm -f

FUNC =	\
		ft_strlen \
		ft_strcpy \
		ft_strcmp \
		ft_write \
		ft_read \
		ft_strdup \

FUNC_BONUS = \
		ft_list_size \
		ft_list_push_front \
		ft_list_remove_if \

SRCDIR = ./srcs
OBJDIR = ./objs
INCDIR = ./incs

SRCS = $(addprefix $(SRCDIR)/, $(addsuffix .s, $(FUNC)))
SRCS_BONUS = $(addprefix $(SRCDIR)/, $(addsuffix _bonus.s, $(FUNC_BONUS)))
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(FUNC)))
OBJS_BONUS = $(addprefix $(OBJDIR)/, $(addsuffix _bonus.o, $(FUNC_BONUS)))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	mkdir $(OBJDIR) 2> /dev/null || true
	$(ACC) $(AFLAGS) $< -o $@

bonus :	$(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $^

clean :
	@$(RM) $(OBJS)

fclean :
	@$(RM) $(NAME) $(NAME_TEST)

re : fclean all

test :
	@$(RM) $(NAME_TEST)
	@$(CC) $(CFLAGS) -I$(INCDIR) main.c -L. -lasm -o $(NAME_TEST)

test_bonus :
	$(RM) $(NAME_TEST)
	$(CC) $(CFLAGS) -I$(INCDIR) main_bonus.c -L. -lasm -o $(NAME_TEST)

.PHONY: all bonus clean fclean test test_bonus re
