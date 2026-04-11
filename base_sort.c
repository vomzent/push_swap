// header

#include "push_swap.h"

void	sort_two(t_stack **a, t_data *data)
{
	int	one;
	int	two;

	one = (*a)->value;
	two = ((*a)->next)->value;
	if (one > two)
		sa(a, data);
}

void	sort_three(t_stack **a, t_data *data)
{
	int	one;
	int	two;
	int	three;

	one = (*a)-> value;
	two = ((*a)->next)->value;
	three = ((*a)->next->next)->value;
	if (one > two && one > three)
		ra(a, data);
	else if (two > one && two > three)
		rra(a, data);
	sort_two(a, data);
}

void	sort_four(t_stack **a, t_stack **b, t_data *data)
{
	int	pos;

	pos = retrieve_pos(*a, find_min(*a));
	while ((*a)->value != find_min(*a))
	{
		if (pos >= 2)
			rra(a, data);
		else	
			ra(a, data);
	}
	pb(a, b, data);
	sort_three(a, data);
	pa(a, b, data);
}

void	sort_five(t_stack **a, t_stack **b, t_data *data)
{
	int	pos;

	pos = retrieve_pos(*a, find_min(*a));
	while (stack_size(*a) > 3)
	{
		while ((*a)->value != find_min(*a))
		{
			if (pos >= 2)
				rra(a, data);
			else	
				ra(a, data);
		}
		pb(a, b, data);
	}
	print_stack(*a);
	sort_three(a, data);
	pa(a, b, data);
	pa(a, b, data);
}

//from og chunk sort.c
int	retrieve_pos(t_stack *B, int found)
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