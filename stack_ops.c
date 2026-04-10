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
#include <stdio.h>

void	swap(t_stack **a)
{
	t_stack	*tmp;
	
	if ((*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

void	sa(t_stack **a, t_data *data)
{
	swap(a);
	data->ops[0]++;
	data->total_ops++;
	ft_printf(1, "sa\n");
}

// void	np_sb(t_stack **B)
// {
// 	t_stack	*tmp;
	
// 	if ((*B)->next == NULL)
// 		return ;
// 	tmp = (*B)->next;
// 	(*B)->next = tmp->next;
// 	tmp->next = *B;
// 	*B = tmp;
// }

void	sb(t_stack **b, t_data *data)
{
	swap(b);
	data->ops[1]++;
	data->total_ops++;
	ft_printf(1, "sb\n");
}

void	ss(t_stack **a, t_stack **b, t_data *data)
{
	swap(a);
	swap(b);
	data->ops[2]++;
	data->total_ops++;
	ft_printf(1, "ss\n");
}

void	pa(t_stack **a, t_stack **b, t_data *data)
{
	int	popped;

	if (!*b)
		return ;
	popped = pop(b);
	push(a, popped);
	data->ops[3]++;
	data->total_ops++;
	ft_printf(1, "pa\n");
}

void	pb(t_stack **a, t_stack **b, t_data *data)
{
	int	popped;

	if (!*a)
		return ;
	popped = pop(a);
	push(b, popped);
	data->ops[4]++;
	data->total_ops++;
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
