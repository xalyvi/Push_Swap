#include "ft_push_swap.h"

void	push_a(t_stack *a, t_stack *b)
{
	if (b->top < 0)
		return ;
	push(a, pop(b));
}

void	push_b(t_stack *a, t_stack *b)
{
	if (a->top < 0)
		return ;
	push(b, pop(a));
}

void	rotate_a(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;
	
	(void)b;
	i = a->top;
	tmp = a->array[i];
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = tmp;
}

void	rotate_b(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;
	
	(void)a;
	i = b->top;
	tmp = b->array[i];
	while(i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = tmp;
}

void	rotate_ab(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;
	
	i = a->top;
	tmp = a->array[i];
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = tmp;
	i = b->top;
	tmp = b->array[i];
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = tmp;
}
