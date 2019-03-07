#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_stack
{
	int		top;
	unsigned	capacity;
	int		*array;
}		t_stack;

/*
** Stack functions
*/

t_stack		*createStack(unsigned capacity);
int		isFull(t_stack *stack);
int		isEmpty(t_stack *stack);
int		push(t_stack *stack, int item);
int		pop(t_stack *stack);
/*
** Utility functions
*/

int		is_command(char *str);
int		is_sorted(int *array, int len);
int		ft_strdig(const char *str);
int		ft_atoi(const char *str);

#endif
