UTILS = ft_utils.c \
	ft_utils2.c \
	ft_str_utils.c \
	ft_str_utils2.c \
	ft_str_utils3.c \
	ft_lst_utils.c \
	ft_commands1.c \
	ft_commands2.c \
	ft_commands3.c \
	ft_commands4.c \
	ft_check_sort.c \
	ft_list_stack.c \
	free_list.c

CHECKER_SRC = $(UTILS) \
		ft_line.c \
		checker/checker.c

PUSH_SWAP_SRC = $(UTILS) \
		push_swap/push_swap.c \
		push_swap/ft_push_utils.c \
		push_swap/ft_sort_small.c \
		push_swap/push_to_a.c \
		push_swap/push_to_be.c \
		push_swap/sort_arr.c \
		push_swap/stack_param.c

CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)

SRCDIR = ./src
OBJDIR = ./obj

CHECKER_SRCS = $(addprefix $(SRCDIR)/, $(CHECKER_SRC))
PUSH_SWAP_SRCS = $(addprefix $(SRCDIR)/, $(PUSH_SWAP_SRC))
CHECKER_OBJS = $(addprefix $(OBJDIR)/, $(CHECKER_OBJ))
PUSH_SWAP_OBJS = $(addprefix $(OBJDIR)/, $(PUSH_SWAP_OBJ))

INCLUDES = -I ./include

CC = gcc
CFLAGS = -Wall -Werror -Wextra

CHECKER = checker
PUSH_SWAP = push_swap

all: $(CHECKER) $(PUSH_SWAP)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/checker
	@mkdir -p $(OBJDIR)/push_swap

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(CHECKER): $(OBJDIR) $(CHECKER_OBJS)
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER)

$(PUSH_SWAP): $(OBJDIR) $(PUSH_SWAP_OBJS)
	@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) -o $(PUSH_SWAP)

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -rf $(CHECKER) $(PUSH_SWAP)

re: fclean all
