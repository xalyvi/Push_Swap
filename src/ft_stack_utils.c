/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:37:48 by srolland          #+#    #+#             */
/*   Updated: 2019/03/13 23:48:56 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*create_stack(unsigned capacity)
{
	t_stack	*stack;

	if ((stack = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	stack->capacity = capacity;
	stack->top = -1;
	if ((stack->array = (int *)malloc(sizeof(int) *
					stack->capacity)) == NULL)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

void	push(t_stack *stack, int item)
{
	stack->array[++stack->top] = item;
}

int		pop(t_stack *stack)
{
	return (stack->array[stack->top--]);
}
