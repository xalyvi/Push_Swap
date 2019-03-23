/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_be.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 19:20:27 by srolland          #+#    #+#             */
/*   Updated: 2019/03/23 19:20:28 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_to_b(t_stack *a, t_stack *b, int count, int print)
{
	if (count == 0)
		return ;
	if (a->top->n < a->med)
	{
		push_b(a, b, 1, print);
		count--;
	}
	else if (a->top->next->n < a->med)
		rotate_a(a, b, 1, print);
	else if (a->bottom->n < a->med)
		reverse_a(a, b, 1, print);
	else
		rotate_a(a, b, 1, print);
	push_to_b(a, b, count, print);
}

void	do_rotate_a(t_xuita *xuita, t_stack *a, t_stack *b)
{
	while (a->top && (a->top->n < xuita->min || a->top->n > xuita->max))
		rotate_a(a, b, 1, xuita->print);
}

void	do_reverse_a(t_xuita *xuita, t_stack *a, t_stack *b)
{
	while (a->top && (a->top->n < xuita->min || a->top->n > xuita->max))
		reverse_a(a, b, 1, xuita->print);
}

void	push_shit_to_b(t_xuita *xuita, t_stack *a, t_stack *b)
{
	int i;

	while (xuita->index < xuita->iter)
	{
		ft_get_min(xuita);
		ft_get_max(xuita);
		ft_get_med_2(xuita);
		i = xuita->loop;
		while (a->top && i--)
		{
			(ft_is_ra(xuita, a) < ft_is_rra(xuita, a))
				? do_rotate_a(xuita, a, b)
				: do_reverse_a(xuita, a, b);
			push_b(a, b, 1, xuita->print);
			if (b->top->ind < xuita->med)
				rotate_b(a, b, 1, xuita->print);
		}
		xuita->index++;
	}
}
