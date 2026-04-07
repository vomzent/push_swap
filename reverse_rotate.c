/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:32:53 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/07 10:27:22 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stddef.h> //use of null in ra
#include <stdio.h>

void	np_rra(t_stack **A)
{
	t_stack	*head;
	t_stack	*prev;

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

void	rra(t_stack **A)
{
	np_rra(A);
	ft_printf(1, "rra\n");
}

void	np_rrb(t_stack **B)
{
	t_stack	*head;
	t_stack	*prev;

	head = *B;
	prev = NULL;
	while (head->next != 0)
	{
		prev = head;
		head = head->next;
	}
	head->next = *B;
	*B = head;
	prev->next = NULL;
}

void	rrb(t_stack **B)
{
	np_rrb(B);
	ft_printf(1, "rrb\n");
}

void	rrr(t_stack **A, t_stack **B)
{
	np_rra(A);
	np_rrb(B);
	ft_printf(1, "rrr\n");

}
