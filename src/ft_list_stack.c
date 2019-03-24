/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 19:15:48 by srolland          #+#    #+#             */
/*   Updated: 2019/03/23 19:15:49 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_add_lst(t_lst **list, t_lst *cur)
{
	t_lst	*elem;

	elem = *list;
	if (!elem)
	{
		*list = cur;
		return ;
	}
	while (elem->next)
		elem = elem->next;
	cur->prev = elem;
	elem->next = cur;
	cur->next = NULL;
}

t_lst		*ft_create_lst(int *tab, int amnt)
{
	t_lst	*cur;
	t_lst	*list;
	int		i;

	list = NULL;
	i = 0;
	while (i < amnt)
	{
		if (!(cur = (t_lst*)malloc(sizeof(t_lst))))
			return (NULL);
		cur->ind = 0;
		cur->n = tab[i];
		cur->next = NULL;
		cur->prev = NULL;
		ft_add_lst(&list, cur);
		i++;
	}
	return (list);
}

t_stack		*ft_create_stack(t_lst *list, int *arr, int amnt)
{
	t_lst	*elem;
	t_stack	*stack;
	int		i;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	elem = list;
	stack->top = elem;
	stack->cap = amnt;
	while (elem->next)
		elem = elem->next;
	stack->bottom = elem;
	elem = list;
	while (elem)
	{
		i = -1;
		while (++i < amnt)
			if (arr[i] == elem->n)
				elem->ind = i;
		elem = elem->next;
	}
	ft_init_stack_param(stack);
	return (stack);
}

t_stack		*ft_init_stack(void)
{
	t_stack	*stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	stack->bottom = NULL;
	stack->top = NULL;
	stack->cap = 0;
	stack->med = 0;
	stack->max = 0;
	stack->min = 0;
	return (stack);
}

t_xuita		*ft_init_xuita(int *arr, t_stack *a, int print)
{
	t_xuita	*xuita;

	if (!(xuita = (t_xuita*)malloc(sizeof(t_xuita))))
		return (NULL);
	xuita->index = 0;
	xuita->mov_1 = 0;
	xuita->mov_2 = 0;
	xuita->id = 0;
	xuita->med = 0;
	xuita->print = print;
	xuita->iter = get_iter_number(a->cap);
	xuita->loop = a->cap / xuita->iter;
	xuita->arr = arr;
	xuita->min = arr[xuita->index * xuita->loop];
	xuita->max = arr[(xuita->index + 1) * xuita->loop];
	return (xuita);
}
