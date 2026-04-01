/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 08:22:07 by odschreu          #+#    #+#             */
/*   Updated: 2026/03/31 11:13:27 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>

void	push(Stack **target, int value)
{
	Stack	*node;
	
	if (*target == NULL)
	{
		*target = malloc(sizeof(Stack));
		if (!*target)
			ft_printf("Error\n");
		(*target)->value = value;
		(*target)->next = NULL;
		return ;
	}
	node = malloc(sizeof(Stack));
	if (!node)
	{
		ft_printf("Error\n");
		return ;
	}
	node->value = value;
	node->next = *target;
	*target = node;
}
// assuming that * target == pointing to the first node in the stack atm

int	pop(Stack **target)
{
	int		popped;
	Stack	*tmp;

	popped = 0;
	if ((*target)->value != 0)
	{
		popped = (*target)->value;
		tmp = (*target)->next;
		free(*target);
		*target = tmp;
	}
	return (popped);
}

int	peek(Stack **target)
{
	int	peek;

	peek = 0;
	if ((*target)->value == 0)
		ft_printf("Error\n");
	else
		peek = (*target)->value;
	return (peek);
}

void	free_stack(Stack **target)
{
	Stack	*tmp;
	
	while (*target != NULL)
	{
		tmp = (*target)->next;
		free(*target);
		*target = tmp;	
	}
}
