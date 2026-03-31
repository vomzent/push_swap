/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:45:03 by odschreu          #+#    #+#             */
/*   Updated: 2026/03/31 11:31:34 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>

void	sa(Stack **A)
{
	Stack	*tmp;
	
	if ((*A)->next == NULL)
		return ;
	tmp = (*A)->next;
	(*A)->next = tmp->next;
	tmp->next = *A;
	*A = tmp;
	ft_printf("sa\n");
}

void	sb(Stack **B)
{
	Stack	*tmp;
	
	if ((*B)->next == NULL)
		return ;
	tmp = (*B)->next;
	(*B)->next = tmp->next;
	tmp->next = *B;
	*B = tmp;
	ft_printf("sb\n");
}

void	ss(Stack **A, Stack **B)
{
	sa(A);
	sb(B);
	ft_printf("ss\n");
}

void	pa(Stack **A, Stack **B)
{
	int	popped;

	popped = pop(B);
	push(A, popped);
	ft_printf("pa\n");
}

void	pb(Stack **A, Stack **B)
{
	int	popped;

	popped = pop(A);
	push(B, popped);
	ft_printf("pb\n");
}

/*

> sa (swap a) = swap the first two elements at the top of stack a. do nothing if there is only one or no elements
> sb (swap b) = swap the first two elements at the top of stack b. do nothing if there is only one or no elements
> ss = sa and sb at the same time


> pa (push a) = take the first element at the top of b and put it at the top of a. do nothing if b is empty
> pb (push b) = take the first element at the top of a and put it at the top of b. do nothing if a is empty


*/