// medium based algorithm

#include "push_swap.h"
#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include <math.h>

void	chunk_sort(t_stack **A, t_stack **B)
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
	ft_printf(1, "t_stack A:\n");
	print_stack(*A);
	ft_printf(1, "\n");
	ft_printf(1, "t_stack B:\n");
	print_stack(*B);
	ft_printf(1, "\n");
	while (*B)
		retrieve_max(A, B);
}

void	retrieve_chunk(t_stack **A, t_stack **B, int *range)
{
	int	count;
	int	*pos;

	count = count_chunk(*A, range);
	ft_printf(1, "chunk counts %d elements\n", count);
	while (count > 0 && *A)
	{
		ft_printf(1, "chunk counts %d elements\n", count);
		while (*A && (!((*A)->value >= range[0] && (*A)->value <= range[1])))
		{
			pos = scan_stack(*A, range);
			check_pos(A, pos);
			if (!pos)
				return ;
			free(pos);
		}
		pb(A, B);
		count--;
	}
}

void	check_pos(t_stack **A, int *pos)
{
	if (pos[0] == -1 && pos[1] == -1)
		return (free(pos));
	if ((pos[0] != -1 || pos[1] != -1) && (pos[0] < pos[1]))
		ra(A);
	else
		rra(A);
}

int	count_chunk(t_stack *A, int *range)
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

int	*scan_t_stack(t_stack *A, int *range)
{
	int		*pos;

	pos = malloc(sizeof(int) * 2);
	if (!A)
		return (NULL);
	pos[0] = find_from_top(A, range);
	pos[1] = find_from_bottom(A, range);
	return (pos);
}

int	find_from_bottom(t_stack *A, int *range)
{
	int	counter;
	
	counter = 0;
	while (A->next)
		A = A->next;
	while (A)
	{
		if (A->value >= range[0] && A->value <= range[1])
		{
			ft_printf(1, "value of bottom hold %d\n", A->value);
			ft_printf(1, "bottom hold pos %d\n", counter);
			return (counter);
		}
		counter++;
		if (!A->previous)
			break ;
		A = A->previous;
	}
	return (-1);
}

int	find_from_top(t_stack *A, int *range)
{
	int	counter;
	
	counter = 0;
	while (A)
	{
		if (A->value >= range[0] && A->value <= range[1])
		{
			ft_printf(1, "value of top hold %d\n", A->value);
			ft_printf(1, "top hold pos %d\n", counter);
			return (counter);
		}
		counter++;
		A = A->next;
	}
	return (-1);
}
// too fucking long ffs
// need to fix this code too because it is a hot mess

void	retrieve_max(t_stack **A, t_stack **B)
{
	int	max;
	int	pos;

	max = 0;
	pos = 0;
	ft_printf(1, "enter retrievemax, B size: %d\n", stack_size(*B));
	while (*B)
	{
		if (*B)
			max = find_max(*B);
		ft_printf(1, "new max to be found: %d\n", max);
		pos = retrieve_pos(*B, max);
		while (*B && (*B)->value != max)
		{
			ft_printf(1, "inner loop, B size: %d, top: %d, looking for: %d, pos: %d\n", stack_size(*B), (*B)->value, max, pos);
			if (pos > stack_size(*B) / 2)
				rrb(B);
			else
				rb(B);
			pos = retrieve_pos(*B, max);
		}
		pa(A, B);
	}
}


int	retrieve_pos(t_stack *B, int	found)
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

int	find_max(t_stack *A)
{
	int		max;
	t_stack	*marker;

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

int	**create_chunk(t_stack **A, int amount)
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


int	*find_range(t_stack **A)
{
	int		*arr;
	int		min;
	int		max;
	t_stack	*marker;

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

