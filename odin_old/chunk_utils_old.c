// header

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	find_from_bottom(t_stack *a, int *range)
{
	int	counter;
	
	counter = 1;
	while (a->next)
		a = a->next;
	ft_printf(1, "%d to %d\n", range[0], range[1]);
	while (a)
	{
		if (a->rank >= range[0] && a->rank <= range[1])
		{
			ft_printf(1, "rank of bottom hold %d\n", a->rank);
			ft_printf(1, "bottom hold pos %d\n", counter);
			return (-counter);
		}
		counter++;
		if (!a->previous)
			break ;
		a = a->previous;
	}
	return (1);
}

int	find_from_top(t_stack *a, int *range)
{
	int	counter;
	
	counter = 0;
	ft_printf(1, "%d to %d\n", range[0], range[1]);
	while (a)
	{
		if (a->rank >= range[0] && a->rank <= range[1])
		{
			ft_printf(1, "rank of top hold %d\n", a->rank);
			ft_printf(1, "top hold pos %d\n", counter);
			return (counter);
		}
		counter++;
		a = a->next;
	}
	return (-1);
}

// int	find_cheapest(t_stack *a, int *range)
// {
// 	int	rank_bottom;
// 	int	rank_top;

// 	rank_bottom = find_from_bottom(a, range);
// 	rank_top = find_from_top(a, range);
// 	if (rank_bottom > rank_top)
// 		return (rank_top);
// 	return (rank_bottom);
// }

int	find_cheapest(t_stack *a, int *range)
{
	int	pos_bottom;
	int	pos_top;

	pos_bottom = find_from_bottom(a, range);
	pos_top = find_from_top(a, range);
	ft_printf(1, "pos_top: %d, pos_bottom: %d\n", pos_top, pos_bottom);
	if (pos_top <= -pos_bottom)
		return (pos_top);
	return (pos_bottom);
}

t_stack	*return_node(t_stack *a, int rank)
{
	while (a->rank != rank)
		a = a->next;
	return (a);
}
