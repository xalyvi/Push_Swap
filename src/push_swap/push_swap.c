/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:39:08 by srolland          #+#    #+#             */
/*   Updated: 2019/03/19 21:47:51 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

static void	ft_sort_shit_ton(t_xuita *xuita, t_stack *a, t_stack *b)
{
	push_shit_to_b(xuita, a, b);
	push_shit_to_a(xuita, a, b);
}

static void	ft_sort_more(t_stack *a, t_stack *b, int print)
{
	int	amnt;

	if (ft_check_sort(a, b, 1))
		return ;
	amnt = a->cap;
	push_to_b(a, b, (amnt / 2), print);
	ft_sort_three_a(a, b, 0, print);
	ft_sort_three_b(a, b, print);
	push_to_a(a, b, print);
}

static void	ft_sort(t_xuita *xuita, t_stack *a, t_stack *b)
{
	if (ft_check_sort(a, b, 1))
		return ;
	if (a->cap <= 3)
		ft_sort_three_a(a, b, 1, xuita->print);
	else if (a->cap <= 6)
		ft_sort_more(a, b, xuita->print);
	else
		ft_sort_shit_ton(xuita, a, b);
}

static void	ft_sort_start(int *arr, t_lst *list, int amnt, int print)
{
	t_stack	*a;
	t_stack	*b;
	t_xuita	*xuita;

	a = ft_create_stack(list, arr, amnt);
	b = ft_init_stack();
	xuita = ft_init_xuita(arr, a, print);
	ft_sort(xuita, a, b);
	free_list(xuita, a, b, arr);
}

int			main(int argc, char *argv[])
{
	t_lst 	*list;
	int		*arr;
	int		*tmp;
	int		i;

	arr = NULL;
	i = 0;
	if (--argc >= 1)
	{
		argv++;
		if (ft_strcmp(argv[0], "-v") == 0)
		{
			i = 1;
			argv++;
			argc--;
		}
		if (argc < 2)
			return (0);
		if (!(tmp = push_arg(argv, argc)))
			return (1);
		list = ft_create_lst(tmp, argc);
		arr = sort_arr(tmp, argc);
		ft_sort_start(arr, list, argc, i);
		free(tmp);
	}
	return (0);
}
