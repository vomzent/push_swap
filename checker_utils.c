/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vcoevert <vcoevert@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 19:50:35 by vcoevert      #+#    #+#                 */
/*   Updated: 2026/04/16 10:50:29 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->next->value < a->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	np_pa(t_stack **a, t_stack **b)
{
	int	popped;
	int	rank;

	if (!*b)
		return ;
	rank = (*b)->rank;
	popped = pop(b);
	push(a, popped);
	(*a)->rank = rank;
}

void	np_pb(t_stack **a, t_stack **b)
{
	int	popped;
	int	rank;

	if (!*a)
		return ;
	rank = (*a)->rank;
	popped = pop(a);
	push(b, popped);
	(*b)->rank = rank;
}

int	perform_operation_1(t_data *data, char *op)
{
	if (!ft_strcmp(op, "sa\n"))
		swap(&data->a);
	else if (!ft_strcmp(op, "sb\n"))
		swap(&data->b);
	else if (!ft_strcmp(op, "ss\n"))
	{
		swap(&data->a);
		swap(&data->b);
	}
	else if (!ft_strcmp(op, "pa\n"))
		np_pa(&data->a, &data->b);
	else if (!ft_strcmp(op, "pb\n"))
		np_pb(&data->a, &data->b);
	else if (!ft_strcmp(op, "ra\n") && data->a && data->a->next)
		rotate(&data->a);
	else
		return (0);
	return (1);
}

int	perform_operation_2(t_data *data, char *op)
{
	if (!ft_strcmp(op, "rb\n") && data->b && data->b->next)
		rotate(&data->b);
	else if (!ft_strcmp(op, "rr\n") && data->a
		&& data->a->next && data->b && data->b->next)
	{
		rotate(&data->a);
		rotate(&data->b);
	}
	else if (!ft_strcmp(op, "rra\n") && data->a && data->a->next)
		reverse_rotate(&data->a);
	else if (!ft_strcmp(op, "rrb\n") && data->b && data->b->next)
		reverse_rotate(&data->b);
	else if (!ft_strcmp(op, "rrr\n") && data->a
		&& data->a->next && data->b && data->b->next)
	{
		reverse_rotate(&data->a);
		reverse_rotate(&data->b);
	}
	else
		return (0);
	return (1);
}
