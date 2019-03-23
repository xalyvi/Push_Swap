/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:35:32 by srolland          #+#    #+#             */
/*   Updated: 2019/03/23 19:04:26 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	push_a_helper(t_stack *a, t_stack *b, t_lst *tmp)
{
	tmp->next = a->top;
	a->top->prev = tmp;
	tmp->prev = NULL;
	a->top = tmp;
	b->bottom = NULL;
	b->top = NULL;
}

void		push_a(t_stack *a, t_stack *b, int p, int x)
{
	t_lst *tmp;

	if (!b->top)
		return ;
	tmp = b->top;
	b->top = tmp->next;
	if (!a->top && !a->bottom)
	{
		tmp->next = NULL;
		a->top = tmp;
		a->bottom = tmp;
	}
	else if (b->cap == 1)
		push_a_helper(a, b, tmp);
	else
	{
		tmp->next = a->top;
		a->top->prev = tmp;
		tmp->prev = NULL;
		a->top = tmp;
	}
	(p) ? write(1, "pa\n", 3) : 0;
	a->cap++;
	b->cap--;
	(x) ? print_stacks(a, b) : 0;
}

static void	push_b_helper(t_stack *a, t_stack *b, t_lst *tmp)
{
	tmp->next = b->top;
	b->top->prev = tmp;
	tmp->prev = NULL;
	b->top = tmp;
	a->bottom = NULL;
	a->top = NULL;
}

void		push_b(t_stack *a, t_stack *b, int p, int x)
{
	t_lst *tmp;

	if (!a->top)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	if (!b->top && !b->bottom)
	{
		tmp->next = NULL;
		b->top = tmp;
		b->bottom = tmp;
	}
	else if (a->cap == 1)
		push_b_helper(a, b, tmp);
	else
	{
		tmp->next = b->top;
		b->top->prev = tmp;
		tmp->prev = NULL;
		b->top = tmp;
	}
	(p) ? write(1, "pb\n", 3) : 0;
	a->cap--;
	b->cap++;
	(x) ? print_stacks(a, b) : 0;
}
