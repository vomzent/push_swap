//header
// medium based algorithm

#include "push_swap.h"
#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include <math.h>

void	chunk_sort(Stack **A, Stack **B)
{
	int	i;
	int	**chunks;
	int	amount_of_chunks;

	amount_of_chunks = (int)sqrt(stack_size(*A));
	chunks = create_chunk(A, amount_of_chunks);
	i = 0;
	while (i < amount_of_chunks)
	{
		retrieve_chunk(A, B, chunks[i]);
		i++;
	}
	ft_printf("Stack A:\n");
	print_stack(*A);
	ft_printf("\n");
	ft_printf("Stack B:\n");
	print_stack(*B);
	ft_printf("\n");
	while (*B)
		retrieve_max(A, B);
}

void	retrieve_chunk(Stack **A, Stack **B, int *range)
{
	int	count;
	int	*pos;

	count = count_chunk(*A, range);
	ft_printf("chunk counts %d elements\n", count);
	while (count > 0)
	{
		ft_printf("chunk counts %d elements\n", count);
		pos = scan_stack(*A, range);
		if (!pos)
			return ;
		if (pos[0] != pos[1])
		{
			while ((!((*A)->value >= range[0] && (*A)->value <= range[1])))
				if (pos[0] > pos[1])
					ra(A);
				else if (pos[0] < pos[1])
					rra(A);
			pos = scan_stack(*A, range);
		}
		pb(A, B);
		count--;
	}
	free(pos);
}

int	count_chunk(Stack *A, int *range)
{
	int	count;

	count = 0;
	while (A)
	{
		if (A->value >= range[0] && A->value <= range[1])
			count++;
		A = A->next;
	}
	return (count);
}

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
// need to fix this code too because it is a hot mess

void	retrieve_max(Stack **A, Stack **B)
{
	int	max;
	int	pos;

	max = 0;
	pos = 0;
	ft_printf("enter retrievemax, B size: %d\n", stack_size(*B));
	while (*B)
	{
		if (*B)
			max = find_max(*B);
		ft_printf("new max to be found: %d\n", max);
		pos = retrieve_pos(*B, max);
		while (*B && (*B)->value != max)
		{
			ft_printf("inner loop, B size: %d, top: %d, looking for: %d, pos: %d\n", stack_size(*B), (*B)->value, max, pos);
			if (pos > stack_size(*B) / 2)
				rrb(B);
			else
				rb(B);
			pos = retrieve_pos(*B, max);
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

int	**create_chunk(Stack **A, int amount)
{
	int	*range;
	int	**chunks;
	int	size;
	int	chunk_size;
	int	i;

	range = find_range(A);
	size = range[1] - range[0];
	chunk_size = size / amount;
	chunks = malloc(sizeof(int *) * amount);
	i = 0;
	while (i < amount)
	{
		chunks[i] = malloc(sizeof(int) * 2);
		if (i == 0)
			chunks[i][0] = range[0];
		else
			chunks[i][0] = range[0] + (chunk_size * i) + 1;
		if (i == amount - 1)
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

