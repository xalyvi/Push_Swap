/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:38:36 by srolland          #+#    #+#             */
/*   Updated: 2019/03/24 19:23:21 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_get_med(t_lst *list, int amnt)
{
	int		med;
	t_lst	*elem;
	int		odd;

	if (!list)
		return (0);
	elem = list;
	odd = (amnt % 2) ? 0 : 1;
	med = (amnt + odd) / 2;
	while (elem)
	{
		if (elem->ind == med)
			return (elem->n);
		elem = elem->next;
	}
	return (0);
}

void	ft_init_stack_param(t_stack *stack)
{
	stack->med = ft_get_med(stack->top, stack->cap);
}
