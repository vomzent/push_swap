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

void	selection_sort(t_stack **A, t_stack **B, t_data *data)
{
	int	*arr;
	
	while (*A)
	{
		arr = find_min_pos(*A);
		while (arr[0] != (*A)->value)
		{
			if (arr[1] > (int)stack_size(*A) / 2)
				rra(A, data);
			else
				ra(A, data);
		}
		pb(A, B, data);
	}
	while (*B)
		pa(A, B, data);
	free(arr);
}

int	*find_min_pos(t_stack *A)
{
	int		*arr;
	int		min;
	int		pos;
	int		counter;
	t_stack	*marker;

	min = A->value;
	pos = 0;
	marker = A;
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
