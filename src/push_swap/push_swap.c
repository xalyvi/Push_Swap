#include "ft_push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack *b;
	int	i;

	if (argc < 2)
		return (1);
	i = (ft_strcmp(argv[1], "-v") == 0) ? 1 : 0;
	if ((a = create_stack(argc - 1 - i)) == NULL || (b =
				create_stack(argc - 1 - i)) == NULL)
		return (write_rt("Error\n", 1));
	if (push_stack(a, i, argc, argv))
		return (1);
	if (check_args(a))
	{
		optimization(a, b);
		quicksort(a, b);
	}
	return (0);
}
