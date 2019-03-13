#include "ft_push_swap.h"

static void	optimize_rotate(t_stack *a, t_stack *b)
{
	int	i;
	int	value;
	int	tmp;

	i = 0;
	value = a->array[a->top];
	tmp = a->top - 1;
	if (value > b->array[b->top] && value < b->array[0])
		return ;
	while (tmp > -1 && (b->array[tmp] > value || b->array[tmp + 1] < value))
	{
		i++;
		tmp--;
	}
	if (i < (b->top + 1) / 2)
		while (b->array[b->top] > value || b->array[0] < value)
			rotate_b(a, b, 1);
	else
		while (b->array[b->top] > value || b->array[0] < value)
			reverse_b(a, b, 1);
}

static void	optimize_order(t_stack *a, t_stack *b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = b->top;
	if (tmp > -1)
	{
		while (tmp > 0 && b->array[tmp] > b->array[tmp - 1] && ++i)
			tmp--;
		if (tmp == -1)
			return ;
		if (i < (b->top + 1) / 2)
			while (b->array[0] > b->array[b->top])
				reverse_b(a, b, 1);
		else
			while (b->array[0] > b->array[b->top])
				rotate_b(a, b, 1);
	}
}

static void	q_push_b(t_stack *a, t_stack *b)
{
	int	value;
	int	done;
	int	tmp;

	done = 0;
	if (a->top > 0)
		if (a->array[a->top] > a->array[a->top - 1])
			swap_a(a, b, 1);
	tmp = b->top;
	value = a->array[a->top];
	while (tmp > -1 && value < b->array[tmp])
		tmp--;
	if (tmp == -1 && !done && ++done)
		optimize_order(a, b);
	tmp = b->top;
	while (tmp > -1 && value < b->array[tmp])
		tmp--;
	if (tmp == -1 && !done && ++done)
		optimize_order(a, b);
	if (!done && ++done)
		optimize_rotate(a, b);
	push_b(a, b, 1);
}

static void	con(t_stack *a, t_stack *b)
{
	if (a->top > 0 && a->array[a->top] > a->array[a->top - 1])
		swap_a(a, b, 1);
	if (a->top > 0 && a->array[0] < a->array[1])
	{
		reverse_a(a, b, 1);
		while (a->top > 0 && a->array[0] < a->array[1])
		{
			push_b(a, b, 1);
			rotate_b(a, b, 1);
			reverse_a(a, b, 1);
		}
		reverse_a(a, b, 1);
		swap_a(a, b, 1);
		while (b->top > -1)
		{
			push_a(a, b, 1);
			rotate_a(a, b, 1);
		}
		rotate_a(a, b, 1);
		rotate_a(a, b, 1);
	}
}

void		optimization(t_stack *a, t_stack *b)
{
	while (a->array[0] < a->array[a->top])
	{
		if (a->array[a->top] > a->array[a->top - 1] && a->top - 1 != 0)
			swap_a(a, b, 1);
		reverse_a(a, b, 1);
		if (a->array[a->top] > a->array[a->top - 1] && a->top - 1 != 0)
			swap_a(a, b, 1);
		while (a->top > 0 && a->array[0] > a->array[a->top] &&
				a->array[0] < a->array[a->top - 1])
		{
			q_push_b(a, b);
			reverse_a(a, b, 1);
			if (a->array[a->top] > a->array[a->top - 1] && a->top - 1 != 0)
				swap_a(a, b, 1);
		}
	}
	while (b->top > -1)
	{
		push_a(a, b, 1);
		if (a->array[a->top] > a->array[a->top - 1] && a->top - 1 != 0)
			swap_a(a, b, 1);
	}
	con(a, b);
}
