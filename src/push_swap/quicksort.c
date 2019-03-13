#include "ft_push_swap.h"

static void	optimize_rotate(t_stack *a, t_stack *b)
{
	int	i;
	int	value;
	int	tmp;

	i = 0;
	value = a->array[a->top];
	tmp = b->top - 1;
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

static void     optimize_order(t_stack *a, t_stack *b)
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
		if (i > (b->top + 1) / 2)
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
	while (tmp > -1 && value > b->array[tmp])
		tmp--;
	if (tmp == -1 && !done && ++done)
		optimize_order(a, b);
	if (!done && ++done)
		optimize_rotate(a, b);
	push_b(a, b, 1);
}

static int	choose_pivot(t_stack *a)
{
	int	i;
	int	split;
	int	tmp;
	int	tmp2;

	split = (a->top + 1 <= 400) ? 2 : 7;
	tmp = a->top;
	while (tmp > 0)
	{
		i = 0;
		tmp2 = a->top;
		while (tmp2 > -1)
		{
			if (a->array[tmp2] < a->array[tmp])
				i++;
			if (i > (a->top + 2) / split)
				break ;
			tmp2--;
		}
		if (i == (a->top + 2) / split)
			break ;
		tmp--;
	}
	return (a->array[tmp]);
}

void	quicksort(t_stack *a, t_stack *b)
{
	int	tmp;
	int	pivot;

	while (!is_sorted(a))
	{
		pivot = choose_pivot(a);
		while (a->array[a->top] < pivot)
			q_push_b(a, b);
		while (1)
		{
			tmp = a->top;
			while (tmp > -1 && a->array[tmp] >= pivot)
				tmp--;
			if (tmp == -1)
				break ;
			while (a->array[a->top] < pivot)
				q_push_b(a, b);
			if (a->top > 0 && a->array[a->top] > a->array[a->top - 1] &&
					a->array[a->top - 1] > pivot)
				swap_a(a, b, 1);
			(!is_sorted(a)) ? rotate_a(a, b, 1) : 0;
		}
	}
	optimize_order(a, b);
	while (b->top > -1)
		push_a(a, b, 1);
}
