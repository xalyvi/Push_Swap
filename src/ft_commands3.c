/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:34:38 by srolland          #+#    #+#             */
/*   Updated: 2019/03/14 20:25:45 by srolland         ###   ########.fr       */
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

// void		reverse_a(t_stack *a, t_stack *b, int p, int x)
// {
// 	int	tmp;
// 	int	i;

// 	if (p)
// 		write(1, "rra\n", 4);
// 	i = 0;
// 	tmp = a->array[0];
// 	while (i < a->top)
// 	{
// 		a->array[i] = a->array[i + 1];
// 		i++;
// 	}
// 	a->array[i] = tmp;
// 	if (x)
// 		print_arrs(a, b);
// }

// void		reverse_b(t_stack *a, t_stack *b, int p, int x)
// {
// 	int	tmp;
// 	int	i;

// 	if (p)
// 		write(1, "rrb\n", 4);
// 	i = 0;
// 	tmp = b->array[0];
// 	while (i < b->top)
// 	{
// 		b->array[i] = b->array[i + 1];
// 		i++;
// 	}
// 	b->array[i] = tmp;
// 	if (x)
// 		print_arrs(a, b);
// }

// void		reverse_ab(t_stack *a, t_stack *b, int p, int x)
// {
// 	int	tmp;
// 	int	i;

// 	if (p)
// 		write(1, "rrr\n", 4);
// 	i = 0;
// 	tmp = a->array[0];
// 	while (i < a->top)
// 	{
// 		a->array[i] = a->array[i + 1];
// 		i++;
// 	}
// 	a->array[i] = tmp;
// 	i = 0;
// 	tmp = b->array[0];
// 	while (i < b->top)
// 	{
// 		b->array[i] = b->array[i + 1];
// 		i++;
// 	}
// 	b->array[i] = tmp;
// 	if (x)
// 		print_arrs(a, b);
// }

// static void	print_num(int *array, int i)
// {
// 	char	*tmp;

// 	if (i > -1)
// 	{
// 		tmp = ft_itoa(array[i]);
// 		write(1, "           ", 11 - ft_strlen(tmp));
// 		write(1, tmp, ft_strlen(tmp));
// 		free(tmp);
// 	}
// 	else
// 		write(1, "           ", 11);
// }

// void		print_arrs(t_stack *a, t_stack *b)
// {
// 	int		i;
// 	int		j;

// 	i = a->top;
// 	j = b->top;
// 	write(1, "+-----A-----+-----B-----+\n", 26);
// 	while (i > -1 || j > -1)
// 	{
// 		write(1, "|", 1);
// 		print_num(a->array, i);
// 		i--;
// 		write(1, "|", 1);
// 		print_num(b->array, j);
// 		j--;
// 		write(1, "|\n", 2);
// 	}
// 	write(1, "+-----------+-----------+\n", 26);
// }
