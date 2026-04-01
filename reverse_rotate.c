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
#include "ft_printf/ft_printf.h"
#include <stddef.h> //use of null in ra
#include <stdio.h>

void	np_rra(Stack **A)
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

void	rra(Stack **A)
{
	np_rra(A);
	ft_printf("rra\n");
}

void	np_rrb(Stack **B)
{
	Stack	*head;
	Stack	*prev;

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

void	rrb(Stack **B)
{
	np_rrb(B);
	ft_printf("rrb\n");
}

void	rrr(Stack **A, Stack **B)
{
	np_rra(A);
	np_rrb(B);
	ft_printf("rrr\n");

}
