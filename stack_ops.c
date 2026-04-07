/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_ops.c                                        :+:      :+:    :+:   */
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

void	np_sa(t_stack **A)
{
	t_stack	*tmp;
	
	if ((*A)->next == NULL)
		return ;
	tmp = (*A)->next;
	(*A)->next = tmp->next;
	tmp->next = *A;
	*A = tmp;
}

void	sa(t_stack **A)
{
	np_sa(A);
	ft_printf(1, "sa\n");
}

void	np_sb(t_stack **B)
{
	t_stack	*tmp;
	
	if ((*B)->next == NULL)
		return ;
	tmp = (*B)->next;
	(*B)->next = tmp->next;
	tmp->next = *B;
	*B = tmp;
}

void	sb(t_stack **B)
{
	np_sb(B);
	ft_printf(1, "sb\n");
}

void	ss(t_stack **A, t_stack **B)
{
	np_sa(A);
	np_sb(B);
	ft_printf(1, "ss\n");
}

void	pa(t_stack **A, t_stack **B)
{
	int	popped;

	if (!*B)
		return ;
	popped = pop(B);
	push(A, popped);
	ft_printf(1, "pa\n");
}

void	pb(t_stack **A, t_stack **B)
{
	int	popped;

	if (!*A)
		return ;
	popped = pop(A);
	push(B, popped);
	ft_printf(1, "pb\n");
}

void	print_stack(t_stack *target)
{
	while (target != NULL)
	{
		ft_printf(1, "%d ", target->value);
		target = (target)->next;
	}
}
