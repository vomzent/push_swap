// header
#include "ft_printf/ft_printf.h"
#include "push_swap.h"

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
