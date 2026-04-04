/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 08:50:49 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/04 09:59:08 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stddef.h>

void	np_ra(Stack **A)
{
	Stack	*head;

	head = *A;
	while (head->next != 0)
		head = head->next;
	head->next = *A;
	*A = (*A)->next;
	head->next->next = NULL;
}

void	np_rb(Stack **B)
{
	Stack	*head;

	head = *B;
	while (head->next != 0)
		head = head->next;
	head->next = *B;
	*B = (*B)->next;
	head->next->next = NULL;
}

void	ra(Stack **A)
{
	np_ra(A);
	ft_printf(1, "ra\n");
}

void	rb(Stack **B)
{
	np_rb(B);
	ft_printf(1, "rb\n");
}

void	rr(Stack **A, Stack **B)
{
	np_ra(A);
	np_rb(B);
	ft_printf(1, "rr\n");
}
