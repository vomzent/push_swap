/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:38:04 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/14 12:06:41 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheapest(t_stack **a, int *range)
{
	int		counter;
	int		reverse;
	int		cheapest;
	t_stack	*marker;

	marker = *a;
	reverse = 1;
	cheapest = (int)stack_size(*a) + 1;
	counter = 0;
	while (marker)
	{
		if (marker->rank >= range[0] && marker->rank <= range[1])
		{
			if (counter < cheapest)
				cheapest = counter;
			if (stack_size(*a) - counter < cheapest)
			{
				cheapest = stack_size(*a) - counter;
				reverse = -1;
			}
		}
		counter++;
		marker = marker->next;
	}
	return (cheapest * reverse);
}

int	retrieve_pos_rank(t_stack *a, int rank)
{
	int		pos;
	int		counter;
	t_stack	*marker;

	marker = a;
	counter = 0;
	while (marker)
	{
		if (marker->rank == rank)
			pos = counter;
		counter++;
		marker = marker->next;
	}
	return (pos);
}

int	find_max_rank(t_stack *a)
{
	int		max;
	t_stack	*marker;

	marker = a;
	max = marker->rank;
	while (marker)
	{
		if (marker->rank > max)
			max = marker->rank;
		marker = marker->next;
	}
	return (max);
}
