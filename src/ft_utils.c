/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:38:01 by srolland          #+#    #+#             */
/*   Updated: 2019/03/23 19:16:31 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			get_iter_number(int n)
{
	if (n <= 100)
		return (3);
	if (n <= 300)
		return (5);
	if (n <= 400)
		return (7);
	return (10);
}

int			is_command(char *str)
{
	static char	*c[11] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	int			i;

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(str, c[i]) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int			repeating_f(int array[], int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_strdig(const char *str)
{
	if (*str == '-' && *(str + 1) >= '0' && *(str + 1) <= '9')
		str++;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

intmax_t	ft_atoi(const char *str)
{
	long	nbr;
	char	neg;

	neg = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	nbr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (neg ? -nbr : nbr);
}
