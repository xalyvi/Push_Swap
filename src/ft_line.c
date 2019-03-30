/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:38:57 by srolland          #+#    #+#             */
/*   Updated: 2019/03/13 23:40:08 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

static int		read_from_fd(char **line)
{
	int		ret;
	char	*tmp;
	char	buf[4];

	ret = -1;
	if ((ret = read(0, buf, 3)))
	{
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
	}
	if (buf[2] != '\n')
		read(0, buf, 2);
	if (!(*line = ft_strjoin(*line, buf)))
		return (-1);
	return (ret);
}

int				get_line(char **line)
{
	char			buf[4];
	int				ret;
	char			*end;
	char			*temp;

	if (line == NULL || read(0, buf, 0) < 0)
		return (-1);
	temp = NULL;
	ret = read_from_fd(&temp);
	if (ret < 0 || !temp)
		return (0);
	end = *line;
	return (1);
}
