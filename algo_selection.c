// header

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stddef.h>
#include <stdlib.h>

double	compute_disorder(Stack *A)
{
	int	mistakes;
	int	total_pairs;
	float	ret;
	Stack	*i;
	Stack	*j;

	mistakes = 0;
	total_pairs = 0;
	i = A;
	j = A->next;
	while (j)
	{
		total_pairs++;
		if (i->value > j->value)
			mistakes++;
		i = i->next;
		j = j->next;
	}
	ft_printf("total_pairs = %d\n", total_pairs);
	ft_printf("mistakes = %d\n", mistakes);
	ret = (double)mistakes / (double)total_pairs;
	return (ret);
}

void	selection_sort(Stack **A, Stack **B)
{
	int	*arr;
	
	while (*A)
	{
		arr = find_min(*A);
		while (arr[0] != (*A)->value)
		{
			if (arr[1] > stack_size(*A) / 2)
				rra(A);
			else
				ra(A);
		}
		pb(A, B);
		// *A = (*A)->next;
	}
	while (*B)
		pa(A, B);
	free(arr);
}

int	*find_min(Stack *A)
{
	int		*arr;
	int		min;
	int		pos;
	int		counter;
	Stack	*marker;

	min = A->value;
	pos = 0;
	marker = A;
	arr = malloc(sizeof(int) * 2);
	counter = 0;
	while (marker)
	{
		if (marker->value < min)
		{
			min = marker->value;
			pos = counter;			
		}
		counter++;
		marker = marker->next;
	}
	arr[0] = min;
	arr[1] = pos;
	return (arr);
}
