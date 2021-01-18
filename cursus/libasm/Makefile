NAME		= libasm.a
NAME_TEST	= test
ACC			= nasm
AFLAGS		= -f macho64
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
AR			= ar
ARFLAGS		= rcs
RM			= rm -rf

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
		ft_list_sort \
		ft_atoi_base \

MAINDIR = ./mandatory/
SRCDIR = ./mandatory/srcs
OBJDIR = ./mandatory/objs
INCDIR = ./mandatory/incs
SRCS = $(addprefix $(SRCDIR)/, $(addsuffix .s, $(FUNC)))
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(FUNC)))

MAINDIR_BONUS = ./bonus/
SRCDIR_BONUS = ./bonus/srcs
OBJDIR_BONUS = ./bonus/objs
INCDIR_BONUS = ./bonus/incs
SRCS_BONUS = $(addprefix $(SRCDIR_BONUS)/, $(addsuffix _bonus.s, $(FUNC_BONUS)))
OBJS_BONUS = $(addprefix $(OBJDIR_BONUS)/, $(addsuffix _bonus.o, $(FUNC_BONUS)))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	@mkdir $(OBJDIR) 2> /dev/null || true
	@$(ACC) $(AFLAGS) $< -o $@

bonus :	$(OBJS) $(OBJS_BONUS)
	@$(AR) $(ARFLAGS) $(NAME) $^

$(OBJDIR_BONUS)/%.o: $(SRCDIR_BONUS)/%.s
	@mkdir $(OBJDIR_BONUS) 2> /dev/null || true
	@$(ACC) $(AFLAGS) $< -o $@

clean :
	@$(RM) $(OBJDIR)
	@$(RM) $(OBJDIR_BONUS)

fclean : clean
	@$(RM) $(NAME) $(NAME_TEST)
	@$(RM) *.dSYM *.txt

re : fclean all

test :
	@$(RM) $(NAME_TEST)
	@$(CC) $(CFLAGS) -I$(INCDIR) $(MAINDIR)main.c -L. -lasm -o $(NAME_TEST)

test_bonus :
	@$(RM) $(NAME_TEST)
	@$(CC) $(CFLAGS) -I$(INCDIR) $(MAINDIR_BONUS)main.c -L. -lasm -o $(NAME_TEST)

.PHONY: all clean fclean bonus re test test_bonus
