/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 19:02:14 by srolland          #+#    #+#             */
/*   Updated: 2019/03/23 19:02:17 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_lst_free(t_lst *curr)
{
	t_lst *tmp;

	while (curr)
	{
		tmp = curr;
		tmp->n = 0;
		tmp->ind = 0;
		tmp->prev = NULL;
		curr = curr->next;
		tmp->next = NULL;
		free(tmp);
	}
}

void	free_stack(t_stack *stack)
{
	if (stack->top)
		ft_lst_free(stack->top);
	free(stack);
}

void	free_list(t_xuita *xuita, t_stack *a, t_stack *b, int *arr)
{
	free(arr);
	free(xuita);
	free_stack(b);
	free_stack(a);
}
