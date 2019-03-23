#include "ft_push_swap.h"
#include <stdio.h>

int	ft_check_sort(t_stack *a, t_stack *b, int check)
{
	t_lst *curr;

	if (check)
		if (b->top != NULL)
			return (0);
	curr = a->top;
	while (curr->next)
	{
		if (curr->ind > curr->next->ind)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	ft_check_sort_b(t_stack *a, t_stack *b)
{
	t_lst *curr;

	(void)a;
	curr = b->top;
	while (curr->next)
	{
		if (curr->ind < curr->next->ind)
			return (0);
		curr = curr->next;
	}
	return (1);
}
