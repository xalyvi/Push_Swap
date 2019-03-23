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
#include <stdio.h>

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

int		*push_arg(char *argv[], int amnt)
{
	intmax_t	tmp;
	int			i;
	int			*arr;

	if (!(arr = (int*)malloc(sizeof(int) * amnt)))
		return (NULL);
	i = 0;
	while (i < amnt)
	{
		if (ft_strdig(*argv))
		{
			tmp = ft_atoi(*argv);
			if (tmp < -2147483648 || tmp > 2147483647)
			{
				free(arr);
				write(1, "Error\n", 6);
				return (NULL);
			}
			arr[i] = tmp;
			i++;
			argv++;
		}
		else
		{
			write(1, "Error\n", 6);
			return (NULL);
		}
	}
	if (repeating_f(arr, amnt))
	{
		free(arr);
		write(1, "Error\n", 6);
		return (NULL);
	}
	return (arr);
}

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
