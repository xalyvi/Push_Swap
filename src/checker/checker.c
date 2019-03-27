/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 22:56:53 by srolland          #+#    #+#             */
/*   Updated: 2019/03/23 20:27:30 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

static int	ft_check_tmp(t_stack *a, t_stack *b, int check)
{
	t_lst *curr;

	if (check)
		if (b->top != NULL)
			return (0);
	curr = a->top;
	while (curr->next)
	{
		if (curr->n > curr->next->n)
			return (0);
		curr = curr->next;
	}
	return (1);
}

static int	get_commands(t_stack *a, t_stack *b, int v)
{
	static void	(*com[11])(t_stack *, t_stack *, int, int) = { swap_a, swap_b,
		swap_ab, push_a, push_b, rotate_a, rotate_b, rotate_ab,
		reverse_a, reverse_b, reverse_ab};
	char		*line;
	int			i;

	if (v)
	{
		write(1, "Init a and b\n\n", 15);
		print_stacks(a, b);
	}
	while (get_line(&line))
	{
		i = is_command(line);
		free(line);
		if (i == -1)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		(*com[i])(a, b, 0, v);
	}
	return (1);
}

static void	ft_listen_start(int *arr, t_lst *list, int amnt, int i)
{
	t_stack	*a;
	t_stack	*b;
	int		j;

	j = 0;
	a = ft_create_stack(list, arr, amnt);
	b = ft_init_stack();
	j = get_commands(a, b, i);
	if (j)
	{
		if (ft_check_tmp(a, b, 1))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_stack(a);
	free_stack(b);
}

static int	ft_get_ch_argv(char **argv, int *argc, int **arr, t_lst **list)
{
	char	**tm;

	tm = NULL;
	if (*argc < 2)
		tm = get_ruby(argv[0], argc);
	if (tm)
	{
		if (!(*arr = push_arg(tm, *argc)))
		{
			free_rub(tm);
			return (0);
		}
	}
	else
	{
		if (!(*arr = push_arg(argv, *argc)))
			return (0);
	}
	*list = ft_create_lst(*arr, *argc);
	if (tm)
		free_rub(tm);
	return (1);
}

int			main(int argc, char *argv[])
{
	t_lst	*list;
	int		*arr;
	int		i;
	int		fr;

	i = 0;
	fr = 0;
	arr = NULL;
	if (--argc >= 1)
	{
		argv++;
		if (ft_strcmp(argv[0], "-v") == 0)
		{
			i = 1;
			argv++;
			argc--;
		}
		fr = ft_get_ch_argv(argv, &argc, &arr, &list);
		if (fr)
			ft_listen_start(arr, list, argc, i);
	}
	if (arr)
		free(arr);
	return (0);
}
