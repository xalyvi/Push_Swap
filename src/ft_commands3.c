/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:34:38 by srolland          #+#    #+#             */
/*   Updated: 2019/03/23 19:15:39 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate_a(t_stack *a, t_stack *b, int p, int x)
{
	t_lst *first;
	t_lst *last;
	t_lst *sec;

	(void)b;
	if (a->cap < 2)
		return ;
	first = a->top;
	sec = first->next;
	last = a->bottom;
	a->top = sec;
	a->bottom = first;
	first->next = NULL;
	first->prev = last;
	sec->prev = NULL;
	last->next = first;
	if (p)
		write(1, "ra\n", 3);
	if (x)
		print_stacks(a, b);
}

void	rotate_b(t_stack *a, t_stack *b, int p, int x)
{
	t_lst *first;
	t_lst *last;
	t_lst *sec;

	(void)a;
	if (b->cap < 2)
		return ;
	first = b->top;
	sec = first->next;
	last = b->bottom;
	b->top = sec;
	b->bottom = first;
	first->next = NULL;
	first->prev = last;
	sec->prev = NULL;
	last->next = first;
	if (p)
		write(1, "rb\n", 3);
	if (x)
		print_stacks(a, b);
}

void	rotate_ab(t_stack *a, t_stack *b, int p, int x)
{
	rotate_a(a, b, 0, 0);
	rotate_b(a, b, 0, 0);
	if (p)
		write(1, "rr\n", 3);
	if (x)
		print_stacks(a, b);
}
