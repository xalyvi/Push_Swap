#include "ft_push_swap.h"

int		ft_is_ra(t_xuita *xuita, t_stack *a)
{
	t_lst	*elem;
	int		count;

	count = 0;
	elem = a->top;
	while (elem && (elem->n < xuita->min || elem->n > xuita->max))
	{
		elem = elem->next;
		count++;
	}
	return (count);
}

int		ft_is_rra(t_xuita *xuita, t_stack *a)
{
	t_lst	*elem;
	int		count;

	count = 0;
	elem = a->bottom;
	while (elem && (elem->n < xuita->min || elem->n > xuita->max))
	{
		elem = elem->prev;
		count++;
	}
	return (count);
}

int		ft_is_rb(t_xuita *xuita, t_stack *b)
{
	int		count;
	t_lst	*elem;

	elem = b->top;
	count = 0;
	while (elem)
	{
		if (elem->n == xuita->arr[xuita->id])
			return (count);
		elem = elem->next;
		count++;
	}
	return (0);
}

int		ft_is_rrb(t_xuita *xuita, t_stack *b)
{
	int		count;
	t_lst	*elem;

	elem = b->bottom;
	count = 0;
	while (elem)
	{
		if (elem->n == xuita->arr[xuita->id])
			return (count);
		elem = elem->prev;
		count++;
	}
	return (0);
}