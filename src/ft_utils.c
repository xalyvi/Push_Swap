#include "ft_push_swap.h"

int	is_command(char *str)
{
	static char	*c[11] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	int		i;

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

int	is_sorted(t_stack *s)
{
	int	i;

	i = s->top;
	while (i > 0)
		if (s->array[i] < s->array[i - 1])
			i--;
		else
			return (0);
	return (1);
}

int	repeating_f(int array[], int len)
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

int	ft_strdig(const char *str)
{
	if (*str == '-' || *str == '+')
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

long	ft_atol(const char *str)
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
