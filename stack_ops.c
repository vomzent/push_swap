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

void	np_sa(Stack **A)
{
	Stack	*tmp;
	
	if ((*A)->next == NULL)
		return ;
	tmp = (*A)->next;
	(*A)->next = tmp->next;
	tmp->next = *A;
	*A = tmp;
}

void	sa(Stack **A)
{
	np_sa(A);
	ft_printf("sa\n");
}

void	np_sb(Stack **B)
{
	Stack	*tmp;
	
	if ((*B)->next == NULL)
		return ;
	tmp = (*B)->next;
	(*B)->next = tmp->next;
	tmp->next = *B;
	*B = tmp;
}

void	sb(Stack **B)
{
	np_sb(B);
	ft_printf("sb\n");
}

void	ss(Stack **A, Stack **B)
{
	np_sa(A);
	np_sb(B);
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
