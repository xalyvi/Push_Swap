/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:38:21 by srolland          #+#    #+#             */
/*   Updated: 2019/03/14 21:13:33 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char		*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char		*ft_itoa(int n)
{
	char			buf[22];
	char			*num;
	int				i;
	unsigned int	tmp;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	tmp = n;
	if (n < 0)
		tmp = -n;
	while (tmp != 0)
	{
		buf[i++] = (tmp % 10) + 48;
		tmp /= 10;
	}
	if (n < 0)
		buf[i++] = '-';
	if ((num = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	while (--i >= 0)
		num[tmp++] = buf[i];
	num[tmp] = '\0';
	return (num);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if ((sub = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (len--)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
