#include "ft_push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		swap_a(t_stack *a, t_stack *b, int p)
{
	(void)b;
	if (p)
		write(1, "sa\n", 3);
	if (a->top < 1)
		return ;
	swap(&(a->array[a->top]), &(a->array[a->top - 1]));
}

void		swap_b(t_stack *a, t_stack *b, int p)
{
	if (p)
		write(1, "sb\n", 3);
	(void)a;
	if (b->top < 1)
		return ;
	swap(&(b->array[b->top]), &(b->array[b->top - 1]));
}


void		swap_ab(t_stack *a, t_stack *b, int p)
{
	if (p)
		write(1, "ss\n", 3);
	if (a->top > 0)
		swap(&(a->array[a->top]), &(a->array[a->top - 1]));
	if (b->top > 0)
		swap(&(b->array[b->top]), &(b->array[b->top - 1]));
}
