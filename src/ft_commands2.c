#include "ft_push_swap.h"

void	push_a(t_stack *a, t_stack *b, int p)
{
	if (p)
		write(1, "pa\n", 3);
	if (b->top < 0)
		return ;
	push(a, pop(b));
}

void	push_b(t_stack *a, t_stack *b, int p)
{
	if (p)
		write(1, "pb\n", 3);
	if (a->top < 0)
		return ;
	push(b, pop(a));
}

void	rotate_a(t_stack *a, t_stack *b, int p)
{
	int	tmp;
	int	i;

	(void)b;	
	if (p)
		write(1, "ra\n", 3);
	i = a->top;
	tmp = a->array[i];
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = tmp;
}

void	rotate_b(t_stack *a, t_stack *b, int p)
{
	int	tmp;
	int	i;
	
	(void)a;
	if (p)
		write(1, "rb\n", 3);
	i = b->top;
	tmp = b->array[i];
	while(i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = tmp;
}

void	rotate_ab(t_stack *a, t_stack *b, int p)
{
	int	tmp;
	int	i;
	
	if (p)
		write(1, "rr\n", 3);
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
