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

void	swap_a(t_stack *a, t_stack *b, int p, int x)
{
	t_lst *first;
	t_lst *sec;
	t_lst *ter;

	(void)b;
	if (a->cap < 2)
		return ;
	first = a->top;
	sec = first->next;
	ter = (sec->next) ? sec->next : NULL;
	a->top = sec;
	if (a->cap == 2)
		a->bottom = first;
	first->next = ter;
	first->prev = sec;
	sec->prev = NULL;
	sec->next = first;
	if (ter)
		ter->prev = first;
	if (p)
		write(1, "sa\n", 3);
	if (x)
		print_stacks(a, b);
}

void	swap_b(t_stack *a, t_stack *b, int p, int x)
{
	t_lst *first;
	t_lst *sec;
	t_lst *ter;

	(void)a;
	if (b->cap < 2)
		return ;
	first = b->top;
	sec = first->next;
	ter = (b->top->next->next) ? b->top->next->next : NULL;
	b->top = sec;
	if (b->cap == 2)
		b->bottom = first;
	first->next = ter;
	first->prev = sec;
	sec->prev = NULL;
	sec->next = first;
	if (ter)
		ter->prev = first;
	if (p)
		write(1, "sb\n", 3);
	if (x)
		print_stacks(a, b);
}

void	swap_ab(t_stack *a, t_stack *b, int p, int x)
{
	swap_a(a, b, 0, 0);
	swap_b(a, b, 0, 0);
	if (p)
		write(1, "ss\n", 3);
	if (x)
		print_stacks(a, b);
}
