#include "ft_push_swap.h"

/*
void	do_commands(t_stack *a, t_stack *b)
{
	
}
*/

int	write_error(void)
{
	write(1, "error\n", 6);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	i;

	if (argc == 1)
		return (1);
	if ((stack_a = createStack(argc - 1)) == NULL)
		return (write_error());
	if ((stack_b = createStack(argc - 1)) == NULL)
		return (write_error());
	i = argc;
	while (--i > 0)
		if (ft_strdig(argv[i]))
			push(stack_a, ft_atoi(argv[i]));
		else
			return (write_error());
	//do_commands(stack_a, stack_b);
	return (0);
}
