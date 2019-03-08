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

int	is_sorted(int *array, int i, int b)
{
	if (b > -1)
		return (0);
	while (i > 0)
		if (array[i] <= array[i - 1])
			i--;
		else
			return (0);
	return (1);
}

int	ft_strdig(const char *str)
{
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	nbr;
	char	neg;

	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
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
