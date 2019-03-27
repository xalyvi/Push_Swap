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

static int		read_from_fd(char **line)
{
	int		ret;
	char	*tmp;
	char	buf[42];

	while ((ret = read(0, buf, 42)))
	{
		buf[ret] = '\0';
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
		free(tmp);
	}
	return (ret);
}

int				get_line(char **line)
{
	char			buf[42];
	int				ret;
	char			*temp;

	if (line == NULL || read(0, buf, 0) < 0)
		return (-1);
	temp = NULL;
	ret = read_from_fd(&temp);
	if (ret < 0 || !temp)
		return (0);
	*line = temp;
	return (1);
}
