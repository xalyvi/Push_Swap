#include "ft_push_swap.h"

static void	get_commands(t_stack *a, t_stack *b, int v)
{
	static void	(*com[11])(t_stack *, t_stack *, int) = { swap_a, swap_b,
		swap_ab, push_a, push_b, rotate_a, rotate_b, rotate_ab,
		reverse_a, reverse_b, reverse_ab};
	char	*line;
	int	i;

	if (v)
	{
		write(1, "Init a and b\n\n", 15);
		print_arrs(a, b);
	}
	while (get_next_line(0, &line))
	{
		i = is_command(line);
		if (i == -1)
		{
			free(line);
			write(1, "Error\n", 6);
			return ;
		}
		(*com[i])(a, b, 0);
		if (v)
			print_arrs(a, b);
		free(line);
	}
	if (is_sorted(a) && b->top == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int	i;	

	if (argc < 2)
		return (1);
	i = (ft_strcmp(argv[1], "-v") == 0) ? 1 : 0;
	if ((a = create_stack(argc - 1 - i)) == NULL || (b =
				create_stack(argc - 1 - i)) == NULL)
                return (write_rt("Error\n", 1));
	if (push_stack(a, i, argc, argv))
		return(1);
	if (check_args(a))
		get_commands(a, b, (i == 1));
	return (0);
}
