#include "ft_push_swap.h"

void	do_rotate_b(t_xuita *xuita, t_stack *a, t_stack *b)
{
	while (b->top && b->top->n != xuita->arr[xuita->id])
	{
		if (xuita->id > 0 && b->top->n == xuita->arr[xuita->id - 1])
		{
			push_a(a, b, 1, xuita->print);
			xuita->mov_1 = 1;
		}
		else if (xuita->id > 1 && xuita->mov_1
			&& b->top->n == xuita->arr[xuita->id - 2])
		{
			push_a(a, b, 1, xuita->print);
			rotate_a(a, b, 1, xuita->print);
			xuita->mov_2 = 1;
		}
		else
			rotate_b(a, b, 1, xuita->print);
	}
}

void	do_reverse_b(t_xuita *xuita, t_stack *a, t_stack *b)
{
	while (b->top && b->top->n != xuita->arr[xuita->id])
	{
		if (xuita->id > 0 && b->top->n == xuita->arr[xuita->id - 1])
		{
			push_a(a, b, 1, xuita->print);
			xuita->mov_1 = 1;
		}
		else if (xuita->id > 1 && xuita->mov_1 &&
			b->top->n == xuita->arr[xuita->id - 2])
		{
			push_a(a, b, 1, xuita->print);
			rotate_a(a, b, 1, xuita->print);
			xuita->mov_2 = 1;
		}
		else
			reverse_b(a, b, 1, xuita->print);
	}
}

void	ft_check_move(t_xuita *xuita, t_stack *a, t_stack *b)
{
	if (xuita->mov_1)
	{
		swap_a(a, b, 1, xuita->print);
		xuita->id--;
		xuita->mov_1 = 0;
	}
	if (xuita->mov_2)
	{
		reverse_a(a, b, 1, xuita->print);
		xuita->id--;
		xuita->mov_2 = 0;
	}
}

void	push_shit_to_a(t_xuita *xuita, t_stack *a, t_stack *b)
{
	xuita->id = b->cap - 1;
	while (b->top)
	{
		(ft_is_rb(xuita, b) < ft_is_rrb(xuita, b))
			? do_rotate_b(xuita, a, b)
			: do_reverse_b(xuita, a, b);
		push_a(a, b, 1, xuita->print);
		ft_check_move(xuita, a, b);
		xuita->id -= 1;
	}
	if (a->bottom->n < a->bottom->prev->n)
	{
		reverse_a(a, b, 1, xuita->print);
		reverse_a(a, b, 1, xuita->print);
		swap_a(a, b, 1, xuita->print);
		rotate_a(a, b, 1, xuita->print);
		rotate_a(a, b, 1, xuita->print);
	}
}

void	push_to_a(t_stack *a, t_stack *b, int print)
{
	if (ft_check_sort(a, b, 1))
		return ;
	push_a(a, b, 1, print);
	push_to_a(a, b, print);
}