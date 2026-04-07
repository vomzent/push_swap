/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 08:22:07 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/04 12:20:54 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>

void	push(t_stack **target, int value)
{
	t_stack	*node;
	
	if (*target == NULL)
	{
		*target = malloc(sizeof(t_stack));
		if (!*target)
			ft_printf(1, "Error\n");
		(*target)->value = value;
		(*target)->next = NULL;
		return ;
	}
	node = malloc(sizeof(t_stack));
	if (!node)
	{
		ft_printf(1, "Error\n");
		return ;
	}
	node->previous = NULL;
	node->value = value;
	node->next = *target;
	(*target)->previous = node;
	*target = node;
}
// assuming that * target == pointing to the first node in the t_stack atm

int	pop(t_stack **target)
{
	int		popped;
	t_stack	*tmp;

	if (!(*target))
		return (0);
	popped = (*target)->value;
	tmp = (*target)->next;
	free(*target);
	*target = tmp;
	if (*target)
		(*target)->previous = NULL;
	return (popped);
}

int	peek(t_stack **target)
{
	int	peek;

	peek = 0;
	if ((*target)->value == 0)
		ft_printf(1, "Error\n");
	else
		peek = (*target)->value;
	return (peek);
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

size_t stack_size(t_stack *target)
{	
	size_t	size;
	
	size = 0;
	while (target)
	{
		target = target->next;
		size++;
	}
	return (size);
}
