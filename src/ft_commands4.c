#include "ft_push_swap.h"


void	reverse_a(t_stack *a, t_stack *b, int p, int x)
{
	t_lst *first;
	t_lst *last;
	t_lst *next_to;

	(void)b;
	if (a->cap < 2)
		return ;
	first = a->top;
	last = a->bottom;
	next_to = last->prev;
	a->top = last;
	a->bottom = next_to;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	last->next = first;
	next_to->next = NULL;
	if (p)
		write(1, "rra\n", 4);
    if (x)
        print_stacks(a, b);
}

void	reverse_b(t_stack *a, t_stack *b, int p, int x)
{
	t_lst *first;
	t_lst *last;
	t_lst *next_to;

	(void)a;
	if (b->cap < 2)
		return ;
	first = b->top;
	last = b->bottom;
	next_to = last->prev;
	b->top = last;
	b->bottom = next_to;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	last->next = first;
	next_to->next = NULL;
	if (p)
		write(1, "rrb\n", 4);
    if (x)
        print_stacks(a, b);
}

void	reverse_ab(t_stack *a, t_stack *b, int p, int x)
{
	reverse_a(a, b, 0, 0);
	reverse_b(a, b, 0, 0);
	if (p)
		write(1, "rrr\n", 4);
    if (x)
        print_stacks(a, b);
}

static void	print_num(int num)
{
	char	*tmp;

	tmp = ft_itoa(num);
	write(1, "           ", 11 - ft_strlen(tmp));
	write(1, tmp, ft_strlen(tmp));
	free(tmp);
}

void		print_stacks(t_stack *a, t_stack *b)
{
    t_lst   *at;
    t_lst   *bt;
	int		i;
	int		j;

	i = a->cap;
    at = a->top;
    bt = b->top;
	j = b->cap;
	write(1, "+-----A-----+-----B-----+\n", 26);
	while (i > 0 || j > 0)
	{
		write(1, "|", 1);
        if (at)
        {
		    print_num(at->n);
		    at = at->next;
        }
        else
            write(1, "           ", 11);
        i--;
		write(1, "|", 1);
		if (bt)
        {
		    print_num(bt->n);
		    bt = bt->next;
        }
        else
            write(1, "           ", 11);
		j--;
		write(1, "|\n", 2);
	}
	write(1, "+-----------+-----------+\n", 26);
}