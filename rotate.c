/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 08:50:49 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/08 11:46:55 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stddef.h>

void	np_ra(t_stack **A)
{
	t_stack	*head;

	head = *A;
	while (head->next != 0)
		head = head->next;
	head->next = *A;
	*A = (*A)->next;
	head->next->next = NULL;
}

void	np_rb(t_stack **B)
{
	t_stack	*head;

	head = *B;
	while (head->next != 0)
		head = head->next;
	head->next = *B;
	*B = (*B)->next;
	head->next->next = NULL;
}

void	ra(t_stack **A, t_data *data)
{
	np_ra(A);
	data->ops[5]++;
	ft_printf(1, "ra\n");
}

void	rb(t_stack **B, t_data *data)
{
	np_rb(B);
	data->ops[6]++;
	ft_printf(1, "rb\n");
}

void	rr(t_stack **A, t_stack **B, t_data *data)
{
	np_ra(A);
	np_rb(B);
	data->ops[7]++;
	ft_printf(1, "rr\n");
}
