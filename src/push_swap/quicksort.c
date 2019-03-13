/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:39:23 by srolland          #+#    #+#             */
/*   Updated: 2019/03/13 23:55:53 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	choose_pivot(t_stack *a)
{
	int	i;
	int	split;
	int	tmp;
	int	tmp2;

	split = (a->top + 1 <= 400) ? 2 : 7;
	tmp = a->top;
	while (tmp > 0)
	{
		i = 0;
		tmp2 = a->top;
		while (tmp2 > -1)
		{
			if (a->array[tmp2] < a->array[tmp])
				i++;
			if (i > (a->top + 2) / split)
				break ;
			tmp2--;
		}
		if (i == (a->top + 2) / split)
			break ;
		tmp--;
	}
	return (a->array[tmp]);
}

static void	push_all_the_way(t_stack *a, t_stack *b, int x)
{
	while (b->top > -1)
		push_a(a, b, 1, x);
}

void		quicksort(t_stack *a, t_stack *b, int x)
{
	int	tmp;
	int	pivot;

	while (!is_sorted(a))
	{
		pivot = choose_pivot(a);
		while (a->array[a->top] < pivot)
			q_push_b(a, b, x);
		while (1)
		{
			tmp = a->top;
			while (tmp > -1 && a->array[tmp] >= pivot)
				tmp--;
			if (tmp < 0)
				break ;
			while (a->array[a->top] < pivot)
				q_push_b(a, b, x);
			if (a->top > 0 && a->array[a->top] > a->array[a->top - 1] &&
					a->array[a->top - 1] > pivot)
				swap_a(a, b, 1, x);
			(!is_sorted(a)) ? rotate_a(a, b, 1, x) : 0;
		}
	}
	optimize_order(a, b, x);
	push_all_the_way(a, b, x);
}
