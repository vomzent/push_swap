/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:32:53 by odschreu          #+#    #+#             */
/*   Updated: 2026/03/31 11:34:13 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h> //use of null in ra
#include <stdio.h>

int	stack_size(Stack *target)
{	
	int	size;
	
	size = 0;
	while (target->next != NULL)
	{
		target = target->next;
		size++;
	}
	return (size);
}


void	rra(Stack **A)
{
	Stack	*head;
	Stack	*prev;

	head = *A;
	prev = NULL;
	while (head->next != 0)
	{
		prev = head;
		head = head->next;
	}
	head->next = *A;
	*A = head;
	prev->next = NULL;
}

// void	rb(Stack **B)
// {

// }

// void	rr(Stack **A, Stack **B)
// {

// }

// void	rra(Stack **A)
// {

// }

// void	rrb(Stack **B)
// {

// }

// void	rrr(Stack **A, Stack **B)
// {
	
// }

/*

> ra (rotate a) = shift up all elements of stack a by one. the first element becomes the last one
> rb (rotate b) = shift up all elements of stack b by one. the first element becomes the last one.
> rr = ra and rb at the same time

> rra (reverse rotate a) = shift down all elements of stack a by one. the last element becomes the first one
> rrb (reverse rotate b) = shift down all elements of stack b by one. the last element becomes the first one.
> rrr = rra and rrb at the same time

*/