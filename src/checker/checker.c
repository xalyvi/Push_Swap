#include "ft_push_swap.h"

static int	write_rt(char *str, int rt)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	return (rt);
}

static int	get_commands(t_stack *a, t_stack *b)
{
	static void	(*com[12])(t_stack *, t_stack *) = {
		swap_a, swap_b, swap_ab, push_a, push_b,
		rotate_a, rotate_b, rotate_ab,
		reverse_a, reverse_b, reverse_ab};
	char		*line;
	int		i;

	write(1, "Init a and b\n", 13);
	print_arrs(a, b);
	while (get_next_line(0, &line))
	{
		i = is_command(line);
		if (i == -1)
		{
			free(line);
			return (write_rt("Error\n", -1));
		}
		(*com[i])(a, b);
		print_arrs(a, b);
		if (is_sorted(a->array, a->top, b->top))
			return (write_rt("OK\n", 1));
		free(line);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	i;

	if (argc < 2)
		return (1);
	if ((stack_a = create_stack(argc - 1)) == NULL)
		return (write_rt("Error\n", 1));
	if ((stack_b = create_stack(argc - 1)) == NULL)
		return (write_rt("Error\n", 1));
	i = argc;
	while (--i > 0)
		if (ft_strdig(argv[i]))
			push(stack_a, ft_atoi(argv[i]));
		else
			return (write_rt("Error\n", 1));
	if (stack_a->top == 0)
		return (write_rt("Only one element!\n", 1));
	if (is_sorted(stack_a->array, stack_a->top, stack_b->top))
		return (write_rt("Already sorted!\n", 1));
	get_commands(stack_a, stack_b);
	return (0);
}
