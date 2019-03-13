/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:08:06 by srolland          #+#    #+#             */
/*   Updated: 2019/03/13 23:11:27 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		swap_a(t_stack *a, t_stack *b, int p, int x)
{
	if (p)
		write(1, "sa\n", 3);
	if (a->top < 1)
		return ;
	swap(&(a->array[a->top]), &(a->array[a->top - 1]));
	if (x)
		print_arrs(a, b);
}

void		swap_b(t_stack *a, t_stack *b, int p, int x)
{
	if (p)
		write(1, "sb\n", 3);
	if (b->top < 1)
		return ;
	swap(&(b->array[b->top]), &(b->array[b->top - 1]));
	if (x)
		print_arrs(a, b);
}

void		swap_ab(t_stack *a, t_stack *b, int p, int x)
{
	if (p)
		write(1, "ss\n", 3);
	if (a->top > 0)
		swap(&(a->array[a->top]), &(a->array[a->top - 1]));
	if (b->top > 0)
		swap(&(b->array[b->top]), &(b->array[b->top - 1]));
	if (x)
		print_arrs(a, b);
}
