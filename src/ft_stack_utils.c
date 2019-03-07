#include "ft_push_swap.h"

t_stack	*createStack(unsigned capacity)
{
	t_stack	*stack;

	if ((stack = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	stack->capacity = capacity;
	stack->top = -1;
	if ((stack->array = (int *)malloc(sizeof(int) *
					stack->capacity)) == NULL)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

int	isFull(t_stack *stack)
{
	return (stack->top == (int)(stack->capacity - 1));
}

int	isEmpty(t_stack *stack)
{
	return (stack->top == -1);
}

int	push(t_stack *stack, int item)
{
	if (isFull(stack))
		return (1);
	stack->array[++stack->top] = item;
	return (0);
}

int	pop(t_stack *stack)
{
	return (stack->array[stack->top--]);
}
