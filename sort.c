/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:37:54 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/13 15:42:45 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

void	selection_sort(t_stack **a, t_stack **b, t_data *data)
{
	int	*arr;
	
	while (*a)
	{
		arr = find_min_pos(*a);
		while (arr[0] != (*a)->value)
		{
			if (arr[1] > (int)stack_size(*a) / 2)
				rra(a, data);
			else
				ra(a, data);
		}
		pb(a, b, data);
	}
	while (*b)
		pa(a, b, data);
	free(arr);
}

void	chunk_sort(t_data *data)
{
	int	i;
	int	**chunks;

	normalize_stack(&data->a);
	i = 0;
	chunks = create_chunks(stack_size(data->a));
	while (chunks[i])
	{
		retrieve_chunk(&data->a, &data->b, data, chunks[i]);
		i++;
	}
	retrieve_max(&data->a, &data->b, data);
	free(chunks);
}

void	radix_sort(t_data *data)
{
	data->disorder = 1;
	return ;
}
