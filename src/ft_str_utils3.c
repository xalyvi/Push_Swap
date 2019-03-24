/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:37:55 by srolland          #+#    #+#             */
/*   Updated: 2019/03/24 19:26:34 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static size_t	amount_of_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != c && *s != '\0')
				s++;
			words++;
		}
	}
	return (words);
}

static void		delete_list(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

static char		**splity(char **list, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] != c && s[i + len] != '\0')
				len++;
			if ((list[j++] = ft_strsub(s, i, len)) == NULL)
			{
				delete_list(list);
				return (NULL);
			}
			i += len;
		}
	}
	list[j] = 0;
	return (list);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**list;

	if (!s || !c || ((list = (char**)malloc(sizeof(char*) *
						(amount_of_words(s, c) + 1)))
				== NULL))
		return (NULL);
	return (splity(list, s, c));
}
