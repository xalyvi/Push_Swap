/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 19:25:22 by srolland          #+#    #+#             */
/*   Updated: 2019/03/23 19:25:24 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_get_min(t_xuita *xuita)
{
	int		index;

	index = xuita->index * xuita->loop;
	(!xuita->index) ? index : index--;
	xuita->min = xuita->arr[xuita->index * xuita->loop];
}

void	ft_get_max(t_xuita *xuita)
{
	int index;

	index = (xuita->index + 1) * xuita->loop;
	xuita->max = xuita->arr[--index];
}

void	ft_get_med_2(t_xuita *xuita)
{
	int offset;
	int	index;

	offset = (!xuita->index) ? 0 : xuita->loop / 2;
	index = (((xuita->index + 1) * xuita->loop) / 2) + (offset * xuita->index);
	xuita->med = xuita->arr[--index];
}
