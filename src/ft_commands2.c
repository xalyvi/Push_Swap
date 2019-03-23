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


static void	push_a_helper(t_stack *a, t_stack *b, t_lst *tmp)
{
	tmp->next = a->top;
	a->top->prev = tmp;
	tmp->prev = NULL;
	a->top = tmp;
	b->bottom = NULL;
	b->top = NULL;
}

void	push_a(t_stack *a, t_stack *b, int p , int x)
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
	if (p)
		write(1, "pa\n", 3);
	a->cap++;
	b->cap--;
	if (x)
		print_stacks(a, b);
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

void	push_b(t_stack *a, t_stack *b, int p , int x)
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
	if (p)
		write(1, "pb\n", 3);
	a->cap--;
	b->cap++;
	if (x)
		print_stacks(a, b);
}














// void	push_a(t_stack *a, t_stack *b, int p, int x)
// {
// 	if (p)
// 		write(1, "pa\n", 3);
// 	if (b->top < 0)
// 		return ;
// 	push(a, pop(b));
// 	if (x)
// 		print_arrs(a, b);
// }

// void	push_b(t_stack *a, t_stack *b, int p, int x)
// {
// 	if (p)
// 		write(1, "pb\n", 3);
// 	if (a->top < 0)
// 		return ;
// 	push(b, pop(a));
// 	if (x)
// 		print_arrs(a, b);
// }

// void	rotate_a(t_stack *a, t_stack *b, int p, int x)
// {
// 	int	tmp;
// 	int	i;

// 	if (p)
// 		write(1, "ra\n", 3);
// 	i = a->top;
// 	tmp = a->array[i];
// 	while (i > 0)
// 	{
// 		a->array[i] = a->array[i - 1];
// 		i--;
// 	}
// 	a->array[0] = tmp;
// 	if (x)
// 		print_arrs(a, b);
// }

// void	rotate_b(t_stack *a, t_stack *b, int p, int x)
// {
// 	int	tmp;
// 	int	i;

// 	if (p)
// 		write(1, "rb\n", 3);
// 	i = b->top;
// 	tmp = b->array[i];
// 	while (i > 0)
// 	{
// 		b->array[i] = b->array[i - 1];
// 		i--;
// 	}
// 	b->array[0] = tmp;
// 	if (x)
// 		print_arrs(a, b);
// }

// void	rotate_ab(t_stack *a, t_stack *b, int p, int x)
// {
// 	int	tmp;
// 	int	i;

// 	if (p)
// 		write(1, "rr\n", 3);
// 	i = a->top;
// 	tmp = a->array[i];
// 	while (i > 0)
// 	{
// 		a->array[i] = a->array[i - 1];
// 		i--;
// 	}
// 	a->array[0] = tmp;
// 	i = b->top;
// 	tmp = b->array[i];
// 	while (i > 0)
// 	{
// 		b->array[i] = b->array[i - 1];
// 		i--;
// 	}
// 	b->array[0] = tmp;
// 	if (x)
// 		print_arrs(a, b);
// }
