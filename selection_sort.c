/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 08:50:39 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/07 10:49:30 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stddef.h>
#include <stdlib.h>

void	selection_sort(t_t_stack **A, t_t_stack **B)
{
	int	*arr;
	
	while (*A)
	{
		arr = find_min(*A);
		while (arr[0] != (*A)->value)
		{
			if (arr[1] > stack_size(*A) / 2)
				rra(A);
			else
				ra(A);
		}
		pb(A, B);
	}
	while (*B)
		pa(A, B);
	free(arr);
}

int	*find_min(t_t_stack *A)
{
	int		*arr;
	int		min;
	int		pos;
	int		counter;
	t_t_stack	*marker;

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
