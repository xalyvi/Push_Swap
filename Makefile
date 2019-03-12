UTILS = ft_utils.c \
	ft_utils2.c \
	ft_stack_utils.c \
	ft_str_utils.c \
	ft_str_utils2.c \
	ft_lst_utils.c \
	ft_get_next_line.c \
	ft_commands1.c \
	ft_commands2.c \
	ft_commands3.c

CHECKER_SRC = $(UTILS) \
	      checker/checker.c

PUSH_SWAP_SRC = $(UTILS) \
		push_swap/push_swap.c \
		push_swap/optimization.c \
		push_swap/quicksort.c

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
CFLAGS = -Wall -Wextra -Werror

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
