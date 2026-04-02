//header
// medium based algorithm

#include "push_swap.h"
#include <stdlib.h>


// void	chunk_sort(Stack **A, Stack **B)
// {

// }


int	**create_chunk(Stack **A)
{
	int	*range;
	int	**chunks;
	int	size;
	int	chunk_size;
	int	i;
	int	chunk_num;

	range = find_range(A);
	size = range[1] - range[0];
	chunk_num = 5;
	chunk_size = size / 5;
	chunks = malloc(sizeof(int *) * chunk_num);
	i = 0;
	while (i < chunk_num)
	{
		chunks[i] = malloc(sizeof(int) * 2);
		if (i == 0)
			chunks[i][0] = range[0];
		else
			chunks[i][0] = range[0] + (chunk_size * i) + 1;
		if (i == chunk_num - 1)
			chunks[i][1] = range[1];
		else
			chunks[i][1] = range[0] + chunk_size + (chunk_size * i);
		i++;
	}
	free(range);
	return (chunks);
}
// need to rewrite this function because it's too long but cba at the moment

int	*find_range(Stack **A)
{
	int		*arr;
	int		min;
	int		max;
	Stack	*marker;

	arr = malloc(sizeof(int) * 2);
	marker = *A;
	max = (*A)->value;
	min = (*A)->value;
	while (marker)
	{
		if (marker->value < min)
			min = marker->value;
		if (marker->value > max)
			max = marker->value;
		marker = marker->next;
	}
	arr[0] = min;
	arr[1] = max;
	return (arr);
}

