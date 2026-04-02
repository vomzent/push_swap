//header
// medium based algorithm

#include "push_swap.h"
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

// void	chunk_sort(Stack **A, Stack **B)
// {
// 	int	max;
// 	int	min;
// 	int	**chunks;

// 	chunks = create_chunk(A);
// 	min = chunks[0][0];
// 	max = chunks[i][1];
// 	while (*A)

// 	while (*B)
// 		retrieve_max(B);
// }

int	*scan_stack(Stack *A, int *range)
{
	int		*pos;
	int		counter;
	Stack	*last;

	pos = malloc(sizeof(int) * 2);
	counter = 0;
	while (A)
	{
		if (A->value >= range[0] && A->value <= range[1])
		{
			ft_printf("value of top hold %d\n", A->value);
			pos[0] = counter;
			break ;
		}
		counter++;
		A = A->next;
	}
	while (A)
	{
		last = A;
		A = A->next;
	}
	A = last;
	counter = 0;
	while (A)
	{
		if (A->value >= range[0] && A->value <= range[1])
		{
			ft_printf("value of bottom hold %d\n", A->value);
			pos[1] = counter;
			break ;
		}
		counter++;
		A = A->previous;
	}
	return (pos);
}
// too fucking long ffs
// also with this approach we need a previous pointer so we can go from bottom to top

void	retrieve_max(Stack **A, Stack **B)
{
	int	max;
	int	pos;

	max = 0;
	pos = 0;
	while (*B)
	{
		max = find_max(*B);
		pos = retrieve_pos(*B, max);
		while ((*B)->value != max)
		{
			if (pos > stack_size(*B) / 2)
				rrb(B);
			else
				rb(B);
		}
		pa(A, B);
	}
}


int	retrieve_pos(Stack *B, int	found)
{
	int	pos;
	int	counter;

	counter = 0;
	pos = 0;
	while (B)
	{
		if (B->value == found)
		{
			pos = counter;
			break;
		}
		counter++;
		B = B->next;
	}
	return (pos);
}

int	find_max(Stack *A)
{
	int		max;
	Stack	*marker;

	max = A->value;
	marker = A;
	while (marker)
	{
		if (marker->value > max)
			max = marker->value;
		marker = marker->next;
	}
	return (max);
}

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
// also not sure if mathlib is allowed (use of sqrt -> or use ft_sqrt from piscine)
// so need to change chunk_num to represent the squared value of stack_size(*A)


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

