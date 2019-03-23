#include "ft_push_swap.h"

void	ft_lst_free(t_lst *curr)
{
	t_lst *tmp;

	while (curr)
	{
		tmp = curr;
		tmp->n = 0;
		tmp->ind = 0;
		tmp->prev = NULL;
		curr = curr->next;
		tmp->next = NULL;
		free(tmp);
	}
}

void	ft_free_arr(int *arr, int amnt)
{
	int	*tmp;
	int	i;

	i = -1;
	while (++i < amnt)
	{
		tmp = arr;
		arr++;
		tmp = NULL;
		free(tmp);
	}
}

void	free_stack(t_stack *stack)
{
	if (stack->top)
		ft_lst_free(stack->top);
	free(stack);
}


void	free_list(t_xuita *xuita, t_stack *a, t_stack *b, int *arr)
{
	ft_free_arr(arr, a->cap);
	free(xuita);
	free_stack(b);
	free_stack(a);
}