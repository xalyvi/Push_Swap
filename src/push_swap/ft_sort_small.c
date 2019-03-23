#include "ft_push_swap.h"

void    ft_sort_three_a(t_stack *a, t_stack *b, int check, int print)
{
    if (ft_check_sort(a, b, check))
        return ;
    if (((a->bottom->n > a->bottom->prev->n) && (a->bottom->n < a->top->n))
		|| (((a->top->n > a->top->next->n) && (a->top->n > a->bottom->n))
		&& (a->bottom->n < a->bottom->prev->n)))
		rotate_a(a, b, 1, print);
	else if (((a->bottom->n > a->top->n) && (a->bottom->n < a->bottom->prev->n))
		|| ((a->top->n < a->top->next->n) && (a->top->n > a->bottom->n)))
		reverse_a(a, b, 1, print);
	else if ((a->top->n > a->top->next->n) && (a->top->n < a->bottom->n))
		swap_a(a, b, 1, print);
	ft_sort_three_a(a, b, check, print);
}

void	ft_sort_three_b(t_stack *a, t_stack *b, int print)
{
	if (ft_check_sort_b(a, b))
		return ;
	if (((b->top->n < b->top->next->n) && (b->top->n < b->bottom->n)
		&& (b->bottom->n > b->bottom->prev->n))
		|| ((b->top->n < b->top->next->n) && (b->top->n < b->bottom->n)
		&& (b->bottom->n < b->bottom->prev->n)))
		rotate_b(a, b, 1, print);
	else if (((b->top->n > b->top->next->n) && (b->top->n < b->bottom->n))
		|| ((b->top->n > b->top->next->n) && (b->top->n > b->bottom->n)
		&& (b->bottom->n > b->bottom->prev->n)))
		reverse_b(a, b, 1, print);
	else if ((b->top->n < b->top->next->n) && (b->top->n > b->bottom->n))
		swap_b(a, b, 1, print);
	ft_sort_three_b(a, b, print);
}