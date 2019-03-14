/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:39:08 by srolland          #+#    #+#             */
/*   Updated: 2019/03/14 20:49:07 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack *b;
	int		i;

	if (argc < 2)
		return (1);
	i = (ft_strcmp(argv[1], "-v") == 0) ? 1 : 0;
	if ((a = create_stack(argc - 1 - i)) == NULL ||
			(b = create_stack(argc - 1 - i)) == NULL)
		return (write_rt("Error\n", 1));
	if (push_stack(a, i, argc, argv))
		return (1);
	if (check_args(a))
	{
		if (i == 1)
		{
			write(1, "Init a and b\n", 13);
			print_arrs(a, b);
		}
		optimization(a, b, (i == 1));
		quicksort(a, b, (i == 1));
	}
	free_stacks(a, b);
	return (0);
}
