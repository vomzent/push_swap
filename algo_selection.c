// header

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stddef.h>

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

void	extract_max(Stack **A, Stack **B)
{
	int	max;
	int	size;

	if (!*A)	
	{
		ft_printf("Error\n");
		return ;
	}
	max = find_max(*A);
	size = stack_size(*A);
	while (size + 1 > 0)
	{
		if ((*A)->value != max)
		{
			pb(A, B);
		}
		else
			*A = (*A)->next;
		size--;
	}
	push(A, max);
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
