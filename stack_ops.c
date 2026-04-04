/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:45:03 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/04 12:20:41 by odschreu         ###   ########.fr       */
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
	ft_printf(1, "sa\n");
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
	ft_printf(1, "sb\n");
}

void	ss(Stack **A, Stack **B)
{
	np_sa(A);
	np_sb(B);
	ft_printf(1, "ss\n");
}

void	pa(Stack **A, Stack **B)
{
	int	popped;

	if (!*B)
		return ;
	popped = pop(B);
	push(A, popped);
	ft_printf(1, "pa\n");
}

void	pb(Stack **A, Stack **B)
{
	int	popped;

	if (!*A)
		return ;
	popped = pop(A);
	push(B, popped);
	ft_printf(1, "pb\n");
}

void	print_stack(Stack *target)
{
	while (target != NULL)
	{
		ft_printf(1, "%d ", target->value);
		target = (target)->next;
	}
}
