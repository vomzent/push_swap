/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 08:50:39 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/09 11:56:56 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stddef.h>
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

int	*find_min_pos(t_stack *a)
{
	int		*arr;
	int		min;
	int		pos;
	int		counter;
	t_stack	*marker;

	min = a->value;
	pos = 0;
	marker = a;
	arr = malloc(sizeof(int) * 2);
	counter = 0;
	while (marker)
	{
		if (marker->value < min)
		{
			min = marker->value;
			pos = counter;			
		}
		counter++;
		marker = marker->next;
	}
	arr[0] = min;
	arr[1] = pos;
	return (arr);
}
