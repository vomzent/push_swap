/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_base.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 15:39:08 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/16 10:53:56 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
