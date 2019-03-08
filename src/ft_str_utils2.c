#include "ft_push_swap.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t 	i;

	i = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_strchr(const char *s, int c)
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

static void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	t;

	if (n < 0)
	{
		write(1, "-", 1);
		t = -n;
	}
	else
		t = n;
	if (n >= 10)
	{
		ft_putnbr(t / 10);
		ft_putnbr(t % 10);
	}
	else if (t < 10)
	{
		ft_putchar(t + '0');
	}
}
