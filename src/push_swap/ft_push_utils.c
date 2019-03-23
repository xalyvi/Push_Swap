/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 19:17:15 by srolland          #+#    #+#             */
/*   Updated: 2019/03/23 20:28:46 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	ft_get_argv(char **argv, int *argc, int **arr, t_lst **list)
{
	int		*tmp;
	char	j;
	char	**tm;

	j = 0;
	tm = NULL;
	if (*argc < 2)
		tm = get_ruby(argv[0], argc);
	if (tm)
	{
		if (!(tmp = push_arg(tm, *argc)))
		{
			free_rub(tm);
			return (0);
		}
	}
	else
	{
		if (!(tmp = push_arg(argv, *argc)))
			return (0);
	}
	*list = ft_create_lst(tmp, *argc);
	*arr = sort_arr(tmp, *argc);
	if (tmp)
		free(tmp);
	if (j)
		free_rub(tm);
	return (1);
}

int		ft_is_ra(t_xuita *xuita, t_stack *a)
{
	t_lst	*elem;
	int		count;

	count = 0;
	elem = a->top;
	while (elem && (elem->n < xuita->min || elem->n > xuita->max))
	{
		elem = elem->next;
		count++;
	}
	return (count);
}

int		ft_is_rra(t_xuita *xuita, t_stack *a)
{
	t_lst	*elem;
	int		count;

	count = 0;
	elem = a->bottom;
	while (elem && (elem->n < xuita->min || elem->n > xuita->max))
	{
		elem = elem->prev;
		count++;
	}
	return (count);
}

int		ft_is_rb(t_xuita *xuita, t_stack *b)
{
	int		count;
	t_lst	*elem;

	elem = b->top;
	count = 0;
	while (elem)
	{
		if (elem->n == xuita->arr[xuita->id])
			return (count);
		elem = elem->next;
		count++;
	}
	return (0);
}

int		ft_is_rrb(t_xuita *xuita, t_stack *b)
{
	int		count;
	t_lst	*elem;

	elem = b->bottom;
	count = 0;
	while (elem)
	{
		if (elem->n == xuita->arr[xuita->id])
			return (count);
		elem = elem->prev;
		count++;
	}
	return (0);
}
