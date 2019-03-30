/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:38:05 by srolland          #+#    #+#             */
/*   Updated: 2019/03/24 19:25:20 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

char		**get_ruby(char *argv, int *argc)
{
	char	**tmp;
	int		j;

	tmp = ft_strsplit(argv, ' ');
	if (tmp[1])
	{
		j = 0;
		while (tmp[j])
			j++;
		*argc = j;
		return (tmp);
	}
	else
		free_rub(tmp);
	return (NULL);
}

static int	push_num(char *argv, int **arr, int i)
{
	intmax_t	tmp;

	if (ft_strdig(argv))
	{
		tmp = ft_atoi(argv);
		if (tmp < -2147483648 || tmp > 2147483647)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		arr[0][i] = (int)tmp;
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int			*push_arg(char *argv[], int amnt)
{
	int			i;
	int			*arr;

	if (!(arr = (int*)malloc(sizeof(int) * amnt)))
		return (NULL);
	i = 0;
	while (i < amnt)
		if (push_num(*argv, &arr, i))
		{
			argv++;
			i++;
		}
		else
		{
			free(arr);
			return (NULL);
		}
	if (repeating_f(arr, amnt))
	{
		free(arr);
		write(1, "Error\n", 6);
		return (NULL);
	}
	return (arr);
}

void		free_rub(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
