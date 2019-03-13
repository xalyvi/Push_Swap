/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:39:18 by srolland          #+#    #+#             */
/*   Updated: 2019/03/13 23:49:41 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		optimize_rotate(t_stack *a, t_stack *b, int x)
{
	int i;
	int value;
	int tmp;

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
			rotate_b(a, b, 1, x);
	else
		while (b->array[b->top] > value || b->array[0] < value)
			reverse_b(a, b, 1, x);
}

void		optimize_order(t_stack *a, t_stack *b, int x)
{
	int i;
	int tmp;

	i = 0;
	tmp = b->top;
	if (tmp > -1)
	{
		while (tmp > 0 && b->array[tmp] > b->array[tmp - 1] && ++i)
			tmp--;
		if (tmp < 0)
			return ;
		if (i > (b->top + 1) / 2)
			while (b->array[0] > b->array[b->top])
				reverse_b(a, b, 1, x);
		else
			while (b->array[0] > b->array[b->top])
				rotate_b(a, b, 1, x);
	}
}

void		q_push_b(t_stack *a, t_stack *b, int x)
{
	int value;
	int done;
	int tmp;

	done = 0;
	if (a->top > 0)
		if (a->array[a->top] > a->array[a->top - 1])
			swap_a(a, b, 1, x);
	tmp = b->top;
	value = a->array[a->top];
	while (tmp > -1 && value < b->array[tmp])
		tmp--;
	if (tmp < 0 && !done && ++done)
		optimize_order(a, b, x);
	tmp = b->top;
	while (tmp > -1 && value > b->array[tmp])
		tmp--;
	if (tmp < 0 && !done && ++done)
		optimize_order(a, b, x);
	if (!done && ++done)
		optimize_rotate(a, b, x);
	push_b(a, b, 1, x);
}

static void	con(t_stack *a, t_stack *b, int x)
{
	if (a->top > 0 && a->array[a->top] > a->array[a->top - 1])
		swap_a(a, b, 1, x);
	if (a->top > 0 && a->array[0] < a->array[1])
	{
		reverse_a(a, b, 1, x);
		while (a->top > 0 && a->array[0] < a->array[1])
		{
			push_b(a, b, 1, x);
			rotate_b(a, b, 1, x);
			reverse_a(a, b, 1, x);
		}
		reverse_a(a, b, 1, x);
		swap_a(a, b, 1, x);
		while (b->top > -1)
		{
			push_a(a, b, 1, x);
			rotate_a(a, b, 1, x);
		}
		rotate_a(a, b, 1, x);
		rotate_a(a, b, 1, x);
	}
}

void		optimization(t_stack *a, t_stack *b, int x)
{
	while (a->array[0] < a->array[a->top])
	{
		if (a->array[a->top] > a->array[a->top - 1] && a->top - 1 > 0)
			swap_a(a, b, 1, x);
		reverse_a(a, b, 1, x);
		if (a->array[a->top] > a->array[a->top - 1] && a->top - 1 > 0)
			swap_a(a, b, 1, x);
		while (a->top > 0 && a->array[0] > a->array[a->top] &&
				a->array[0] < a->array[a->top - 1])
		{
			q_push_b(a, b, x);
			reverse_a(a, b, 1, x);
			if (a->array[a->top] > a->array[a->top - 1] && a->top - 1 > 0)
				swap_a(a, b, 1, x);
		}
	}
	while (b->top > -1)
	{
		push_a(a, b, 1, x);
		if (a->array[a->top] > a->array[a->top - 1] && a->top - 1 > 0)
			swap_a(a, b, 1, x);
	}
	con(a, b, x);
}
