/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:35:32 by srolland          #+#    #+#             */
/*   Updated: 2019/03/13 23:37:40 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_a(t_stack *a, t_stack *b, int p, int x)
{
	if (p)
		write(1, "pa\n", 3);
	if (b->top < 0)
		return ;
	push(a, pop(b));
	if (x)
		print_arrs(a, b);
}

void	push_b(t_stack *a, t_stack *b, int p, int x)
{
	if (p)
		write(1, "pb\n", 3);
	if (a->top < 0)
		return ;
	push(b, pop(a));
	if (x)
		print_arrs(a, b);
}

void	rotate_a(t_stack *a, t_stack *b, int p, int x)
{
	int	tmp;
	int	i;

	if (p)
		write(1, "ra\n", 3);
	i = a->top;
	tmp = a->array[i];
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = tmp;
	if (x)
		print_arrs(a, b);
}

void	rotate_b(t_stack *a, t_stack *b, int p, int x)
{
	int	tmp;
	int	i;

	if (p)
		write(1, "rb\n", 3);
	i = b->top;
	tmp = b->array[i];
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = tmp;
	if (x)
		print_arrs(a, b);
}

void	rotate_ab(t_stack *a, t_stack *b, int p, int x)
{
	int	tmp;
	int	i;

	if (p)
		write(1, "rr\n", 3);
	i = a->top;
	tmp = a->array[i];
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = tmp;
	i = b->top;
	tmp = b->array[i];
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = tmp;
	if (x)
		print_arrs(a, b);
}
