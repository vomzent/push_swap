/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:39:35 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/13 15:41:57 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	retrieve_pos(t_stack *a, int found)
{
	int	pos;
	int	counter;

	counter = 0;
	pos = 0;
	while (a)
	{
		if (a->value == found)
		{
			pos = counter;
			break;
		}
		counter++;
		a = a->next;
	}
	return (pos);
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
