/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 11:44:25 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/16 10:52:24 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	**create_chunks(int stack_size)
{
	int	size;
	int	**chunks;
	int	amount;
	int	i;

	size = 1.5 * chunk_size(stack_size);
	amount = stack_size / size;
	chunks = malloc(sizeof(int *) * (amount + 1));
	i = 0;
	while (i < amount)
	{
		chunks[i] = malloc(sizeof(int) * 2);
		chunks[i][0] = size * i;
		if (i == amount - 1)
			chunks[i][1] = stack_size - 1;
		else
			chunks[i][1] = size * (i + 1) - 1;
		i++;
	}
	chunks[i] = NULL;
	return (chunks);
}

int	chunk_size(int stack_size)
{
	int	chunks;
	int	chunk_size;

	chunk_size = 0;
	chunks = 1;
	while (chunks * chunks < stack_size)
		chunks++;
	chunk_size = stack_size / chunks;
	return (chunk_size);
}

int	count_chunk(t_stack *a, int *range)
{
	int	count;

	count = 0;
	while (a)
	{
		if (a->rank >= range[0] && a->rank <= range[1])
			count++;
		a = a->next;
	}
	return (count);
}

void	retrieve_chunk(t_stack **a, t_stack **b, t_data *data, int *range)
{
	int		retrieval;
	int		pos;
	int		reverse;

	retrieval = count_chunk(*a, range);
	while (retrieval > 0)
	{
		reverse = 0;
		pos = find_cheapest(a, range);
		if (pos < 0)
		{
			pos *= -1;
			reverse = 1;
		}
		while (pos > 0)
		{
			if (reverse)
				rra(a, data);
			else
				ra(a, data);
			pos--;
		}
		pb(a, b, data);
		retrieval--;
	}
}

void	retrieve_max(t_stack **a, t_stack **b, t_data *data)
{
	int	rank;
	int	pos;
	int	size;

	rank = -1;
	while (*b)
	{
		rank = find_max_rank(*b);
		pos = retrieve_pos_rank(*b, rank);
		size = stack_size(*b);
		if (pos > size / 2)
			while (*b && (*b)->rank != rank)
				rrb(b, data);
		else
			while (*b && (*b)->rank != rank)
				rb(b, data);
		pa(a, b, data);
	}
}
