// header

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <limits.h>

double	compute_disorder(t_stack *a)
{
	int	mistakes;
	int	total_pairs;
	float	ret;
	t_stack	*i;
	t_stack	*j;

	mistakes = 0;
	total_pairs = 0;
	i = a;
	j = a->next;
	while (j)
	{
		total_pairs++;
		if (i->value > j->value)
			mistakes++;
		i = i->next;
		j = j->next;
	}
	ret = (double)mistakes / (double)total_pairs;
	return (ret);
}

int	normalize_stack(t_stack **stack)
{
	size_t	i;
	t_stack	*ptr;

	i = 0;
	ptr = *stack;
	while (i < stack_size(*stack))
	{
		while (ptr->value != find_min_rank(*stack))
			ptr = ptr->next;
		ptr->rank = i;
		ptr = *stack;
		i++;
	}
	return (0);
}

int	find_min_rank(t_stack *stack)
{
	int		min;
	t_stack	*marker;
	
	marker = stack;
	min = INT_MAX;
	while (marker)
	{
		if (marker->value < min && marker->rank == -1)
			min = marker->value;
		marker = marker->next;
	}
	return (min);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*marker;
	
	marker = stack;
	min = stack->value;
	while (marker)
	{
		if (marker->value < min)
			min = marker->value;
		marker = marker->next;
	}
	return (min);
}

void	print_stack_rank(t_stack *target)
{
	while (target != NULL)
	{
		ft_printf(1, "%d ", target->rank);
		target = (target)->next;
	}
}
