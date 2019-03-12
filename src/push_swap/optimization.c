#include "ft_push_swap.h"

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
			push_b(a, b, 1);
			rotate_b(a, b, 1);
		}
		rotate_a(a, b, 1);
		rotate_a(a, b, 1);
	}
}

void		optimization(t_stack *a, t_stack *b)
{
	while (a->array[0] < a->array[a->top])
	{
		if (a->array[a->top] > a->array[a->top - 1] &&
				a->array[0] != a->array[a->top - 1])
			swap_a(a, b, 1);
		reverse_a(a, b, 1);
		if (a->array[a->top] > a->array[a->top - 1] &&
				a->array[0] != a->array[a->top - 1])
			swap_a(a, b, 1);
		while (a->top > 0 && a->array[0] > a->array[a->top] &&
				a->array[0] < a->array[a->top - 1])
		{
			q_push_b(a, b);
			reverse_a(a, b, 1);
			if (a->array[a->top] > a->array[a->top - 1] &&
					a->array[0] != a->array[a->top - 1])
				swap_a(a, b, 1);
		}
	}
	while (b->top > -1)
	{
		push_a(a, b, 1);
		if (a->array[a->top] > a->array[a->top - 1] &&
				a->array[0] != a->array[a->top - 1])
			swap_a(a, b, 1);
	}
	con(a, b);
}
