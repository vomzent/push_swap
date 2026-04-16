/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_core2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 15:39:20 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/16 10:54:29 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>

void	reverse_rotate(t_stack **a)
{
	t_stack	*head;
	t_stack	*prev;

	head = *a;
	prev = NULL;
	while (head->next != 0)
	{
		prev = head;
		head = head->next;
	}
	head->next = *a;
	*a = head;
	prev->next = NULL;
}

void	print_stack(t_stack *target)
{
	while (target != NULL)
	{
		ft_printf(1, "%d ", target->value);
		target = (target)->next;
	}
}

void	free_stack(t_stack **target)
{
	t_stack	*tmp;

	while (*target != NULL)
	{
		tmp = (*target)->next;
		free(*target);
		*target = tmp;
	}
}

int	stack_size(t_stack *target)
{
	int	size;

	size = 0;
	while (target)
	{
		target = target->next;
		size++;
	}
	return (size);
}
