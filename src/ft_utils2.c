/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:38:05 by srolland          #+#    #+#             */
/*   Updated: 2019/03/13 23:44:12 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	write_rt(char *str, int rt)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	return (rt);
}

int	push_stack(t_stack *a, int st, int en, char *argv[])
{
	long	tmp;

	while (--en > st)
		if (ft_strdig(argv[en]))
		{
			tmp = ft_atol(argv[en]);
			if (tmp < -2147483648 || tmp > 2147483647)
				return (write_rt("Error\n", 1));
			push(a, (int)tmp);
		}
		else
			return (write_rt("Error\n", 1));
	return (0);
}

int	check_args(t_stack *a)
{
	if (repeating_f(a->array, a->top + 1))
		return (write_rt("Error\n", 0));
	if (a->top == 0)
		return (write_rt("Only one element!\n", 0));
	if (is_sorted(a))
		return (write_rt("Already sorted!\n", 0));
	return (1);
}
