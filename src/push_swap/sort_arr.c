#include "ft_push_swap.h"

static int  sort(int *arr, int amnt)
{
    int i;

    i = 0;
    while (i < amnt - 1)
    {
        if (arr[i] > arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}

static void swap(int *arr, int index, int *pivot, int amnt)
{
    int tmp;

    if ((*pivot == amnt) || (*pivot - index) > 1)
    {
        tmp = arr[*pivot - 1];
        arr[*pivot - 1] = arr[*pivot];
        arr[*pivot] = tmp;
        (*pivot)--;
        tmp = arr[*pivot + 1];
        arr[*pivot + 1] = arr[index];
        arr[index] = tmp;
    }
    else
    {
        tmp = arr[*pivot];
        arr[*pivot] = arr[index];
        arr[index] = tmp;
    }    
}

static void  quicksort(int *arr, int *pivot, int amnt)
{
    int i;
    int tmp;

    if (sort(arr, amnt))
        return ;
    if (*pivot == -1)
        *pivot = amnt - 1;
    i = 0;
    while (i < *pivot)
    {
        tmp = arr[i];
        if (arr[i] > arr[*pivot])
            swap(arr, i, pivot, amnt);
        if (tmp == arr[i])
            i++;
    }
    (*pivot)--;
    quicksort(arr, pivot, amnt);
}

int			*sort_arr(int *arr, int amnt)
{
	int	*pivot;

	if (!(pivot = (int*)malloc(sizeof(int))))
		return (0);
	*pivot = amnt - 1;
	quicksort(arr, pivot, amnt);
	free(pivot);
	return (arr);
}   