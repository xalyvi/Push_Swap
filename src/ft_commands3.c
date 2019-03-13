/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:34:38 by srolland          #+#    #+#             */
/*   Updated: 2019/03/13 23:35:14 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	reverse_a(t_stack *a, t_stack *b, int p, int x)
{
	int	tmp;
	int	i;

	if (p)
		write(1, "rra\n", 4);
	i = 0;
	tmp = a->array[0];
	while (i < a->top)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[i] = tmp;
	if (x)
		print_arrs(a, b);
}

void	reverse_b(t_stack *a, t_stack *b, int p, int x)
{
	int	tmp;
	int	i;

	if (p)
		write(1, "rrb\n", 4);
	i = 0;
	tmp = b->array[0];
	while (i < b->top)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->array[i] = tmp;
	if (x)
		print_arrs(a, b);
}

void	reverse_ab(t_stack *a, t_stack *b, int p, int x)
{
	int	tmp;
	int	i;

	if (p)
		write(1, "rrr\n", 4);
	i = 0;
	tmp = a->array[0];
	while (i < a->top)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[i] = tmp;
	i = 0;
	tmp = b->array[0];
	while (i < b->top)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->array[i] = tmp;
	if (x)
		print_arrs(a, b);
}

void	print_arrs(t_stack *a, t_stack *b)
{
	int	i;

	i = (int)a->capacity - 1;
	while (i >= 0)
	{
		if (i <= a->top)
			ft_putnbr(a->array[i]);
		else
			write(1, "_", 1);
		write(1, " ", 1);
		if (i <= b->top)
			ft_putnbr(b->array[i]);
		else
			write(1, "_", 1);
		write(1, "\n", 1);
		i--;
	}
	write(1, "\n_ _\na b\n\n\n", 11);
}
