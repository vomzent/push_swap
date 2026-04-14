/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:39:35 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/14 12:28:50 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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
			break ;
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

int	check_sort(t_stack *a)
{
	t_stack	*next;

	while (a)
	{
		if (!a->next)
			return (0);
		next = a->next;
		if (next->value < a->value)
			return (1);
		a = next;
	}
	return (0);
}
