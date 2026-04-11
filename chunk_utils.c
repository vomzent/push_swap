/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:44:25 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/09 12:16:21 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	**create_chunks(int stack_size)
{
	int	size;
	int	**chunks;
	int	amount;
	int	i;

	size = chunk_size(stack_size);
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
	int		amount;
	int		rank;
	t_stack	*ret;

	amount = count_chunk(*a, range);
	rank = -1;
	while (amount > 0)
	{
		rank = find_cheapest(*a, range);
		ret = return_node(*a, rank);
		while (*a != ret)
		{
			if (rank > (int)stack_size(*a) / 2)
				rra(a, data);
			else
				ra(a, data);
		}
		pa(a, b, data);
		amount--;
	}
}

void	retrieve_max(t_stack **a, t_stack **b, t_data *data)
{
	int	rank;

	rank = -1;
	ft_printf(1, "enter retrievemax, B size: %d\n", stack_size(*b));
	while (*b)
	{
		rank = find_max_rank(*b);
		ft_printf(1, "new max to be found: %d\n", rank);
		while (*b && (*b)->rank != rank)
			rb(b, data);
		pa(a, b, data);
	}
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
