#include "ft_push_swap.h"

int	is_command(char *str)
{
	static char	*c[12] = {"sa", "sb", "ss", "pa", "pb",
		"pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	int		i;
	int		j;

	i = 0;
	while (i < 12)
	{
		j = 0;
		while (c[i][j] || str[j])
			if (c[i][j] == str[j])
				j++;
			else
				return (0);
		i++;
	}
	return (1);
}

int	is_sorted(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
		if (array[i] >= array[i + 1])
			i++;
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
	int		i;
	long long int	result;
	long long int	neg;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] == 32 || str[i] == 10 || str[i] == 9 || str[i] == 12 ||
			str[i] == 13 || str[i] == 11)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || 57 < str[i])
			return (result * neg);
		else
			return (result * 10) + (long long int)(str[i] - '0');
		i++;
	}
	return (result * neg);
}
