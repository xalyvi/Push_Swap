/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:38:05 by srolland          #+#    #+#             */
/*   Updated: 2019/03/19 21:31:40 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		write_rt(char *str, int rt)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	return (rt);
}

int		get_ruby(int i, char ***argv, int *argc)
{
	char	**tmp;
	int		j;

	tmp = ft_strsplit(argv[0][i], ' ');
	if (tmp[1])
	{
		*argv = tmp;
		j = 0;
		while (argv[0][j])
			j++;
		*argc = (i == 1) ? (j + 1) : (j + 2);
		return (1);
	}
	else
	{
		free(tmp[0]);
		free(tmp);
	}
	return (0);
}

int		push_stack(t_stack *a, int st, int en, char *argv[])
{
	intmax_t	tmp;

	while (--en > st)
	{
		if (ft_strdig(argv[en]))
		{
			tmp = ft_atol(argv[en]);
			if (tmp < -2147483648 || tmp > 2147483647)
				return (write_rt("Error\n", 1));
			push(a, (int)tmp);
		}
		else
			return (write_rt("Error\n", 1));
	}
	return (0);
}

int		check_args(t_stack *a)
{
	if (repeating_f(a->array, a->top + 1))
		return (write_rt("Error\n", 0));
	return (1);
}
