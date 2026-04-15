/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   checker_utils.c                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/14 19:50:35 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/04/15 12:29:16 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_stack_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->next->value < a->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	np_pa(t_stack **a, t_stack **b)
{
	int	popped;
	int	rank;

	if (!*b)
		return ;
	rank = (*b)->rank;
	popped = pop(b);
	push(a, popped);
	(*a)->rank = rank;
}

void	np_pb(t_stack **a, t_stack **b)
{
	int	popped;
	int	rank;

	if (!*a)
		return ;
	rank = (*a)->rank;
	popped = pop(a);
	push(b, popped);
	(*b)->rank = rank;
}
