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

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack *b;
	int		i;
	int		j;

	if (argc < 2)
		return (1);
	i = (ft_strcmp(argv[1], "-v") == 0) ? 1 : 0;
	if (argc < 4)
		j = (!i) ? get_ruby(1, &argv, &argc) : get_ruby(2, &argv, &argc);
	if ((a = create_stack(argc - 1 - i)) == NULL ||
			(b = create_stack(argc - 1 - i)) == NULL)
		return (write_rt("Error\n", 1));
	if (push_stack(a, i - j - ((i && j) ? 1 : 0),
				argc - j - ((i && j) ? 1 : 0), argv))
		return (1);
	if (check_args(a))
	{
		(i) ? write(1, "Init a and b\n", 13) : 0;
		(i) ? print_arrs(a, b) : 0;
		optimization(a, b, (i == 1));
		quicksort(a, b, (i == 1));
	}
	free_stacks(a, b);
	return (0);
}
