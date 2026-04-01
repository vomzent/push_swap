// header

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

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

// void	selection_sort(Stack **A, Stack **B)
// {

// }

// void	selection_base(Stack **A)
// {

// }

/*
function compute_disorder(stack a):
	mistakes = 0
	total_pairs = 0
	for i from 0 to size(a)-1:
		for j from i+1 to size(a)-1:
			total_pairs += 1
			if a[i] > a[j]:
				mistakes += 1
	return mistakes / total_pairs
*/