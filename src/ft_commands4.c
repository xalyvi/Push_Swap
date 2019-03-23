/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 19:05:27 by srolland          #+#    #+#             */
/*   Updated: 2019/03/23 19:14:19 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			reverse_a(t_stack *a, t_stack *b, int p, int x)
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

void			reverse_b(t_stack *a, t_stack *b, int p, int x)
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

void			reverse_ab(t_stack *a, t_stack *b, int p, int x)
{
	reverse_a(a, b, 0, 0);
	reverse_b(a, b, 0, 0);
	if (p)
		write(1, "rrr\n", 4);
	if (x)
		print_stacks(a, b);
}

static t_lst	*print_num(t_lst *elem)
{
	char	*tmp;

	if (elem)
	{
		tmp = ft_itoa(elem->n);
		write(1, "           ", 11 - ft_strlen(tmp));
		write(1, tmp, ft_strlen(tmp));
		elem = elem->next;
		free(tmp);
	}
	else
		write(1, "           ", 11);
	return (elem);
}

void			print_stacks(t_stack *a, t_stack *b)
{
	t_lst	*at;
	t_lst	*bt;
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
		at = print_num(at);
		i--;
		write(1, "|", 1);
		bt = print_num(bt);
		j--;
		write(1, "|\n", 2);
	}
	write(1, "+-----------+-----------+\n", 26);
}
