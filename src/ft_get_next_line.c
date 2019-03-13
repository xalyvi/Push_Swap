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

static t_list	*get_fd(t_list **list, int fd)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(list, tmp);
	return (tmp);
}

static int		ft_strccpy(char **dest, const char *src, char c)
{
	int	len;

	len = -1;
	while (src[++len])
		if (src[len] == c)
			break ;
	*dest = ft_strsub(src, 0, len);
	return (len);
}

static int		read_from_fd(const int fd, char **line)
{
	int		ret;
	char	*temp;
	char	buf[43];

	while ((ret = read(fd, buf, 42)))
	{
		buf[ret] = '\0';
		temp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

static void		ft_lstfone(t_list **list, t_list *one)
{
	t_list	*temp;

	if (!list || !*list || !one)
		return ;
	temp = *list;
	while (temp)
		if (temp == one)
			break ;
		else
			temp = temp->next;
	free(temp->content);
	temp->content = (char *)malloc(sizeof(char));
}

int				get_next_line(const int fd, char **line)
{
	char			buf[43];
	static t_list	*list = 0;
	int				ret;
	t_list			*now;
	char			*temp;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	now = get_fd(&list, fd);
	temp = now->content;
	ret = read_from_fd(fd, &temp);
	now->content = temp;
	if (ret < 42 && !*temp)
		return (0);
	ret = ft_strccpy(line, now->content, '\n');
	if (temp[ret] != '\0')
	{
		now->content = ft_strdup(&((now->content)[ret + 1]));
		free(temp);
	}
	else
		ft_lstfone(&list, now);
	return (1);
}
