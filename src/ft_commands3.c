#include "ft_push_swap.h"

void	reverse_a(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;
	
	(void)b;
	i = 0;
	tmp = a->array[0];
	while (i < a->top)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[i] = tmp;
}

void	reverse_b(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;
	
	(void)a;
	i = 0;
	tmp = b->array[0];
	while (i < b->top)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->array[i] = tmp;
}

void	reverse_ab(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;
	
	i = 0;
	tmp = a->array[0];
	while (i < a->top)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[i] = tmp;
	i = 0;
	tmp = b->array[0];
	while (i < b->top)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->array[i] = tmp;
}

void	print_arrs(t_stack *a, t_stack *b)
{
	int	i;

	i = a->top;
	write(1, "a:  ", 4);
	while (i > -1)
	{
		ft_putnbr(a->array[i]);
		write(1, " ", 1);
		i--;
	}
	write(1, "\nb:  ", 5);
	i = b->top;
	while (i > -1)
	{
		ft_putnbr(b->array[i]);
		write(1, " ", 1);
		i--;
	}
	write(1, "\n", 1);
}
