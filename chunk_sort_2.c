/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:44:25 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/09 12:16:21 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	normalize_stack(t_stack **stack)
{
	size_t	i;
	t_stack	*ptr;

	i = 0;
	ptr = *stack;
	while (i < stack_size(*stack))
	{
		while (ptr->value != find_min(*stack))
			ptr = ptr->next;
		ptr->rank = i;
		ptr = *stack;
		i++;
	}
	return (0);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*marker;
	
	marker = stack;
	min = stack->value;
	while (marker)
	{
		if (marker->value < min && marker->rank == -1)
			min = marker->value;
		marker = marker->next;
	}
	return (min);
}

int	main(void)
{
	t_stack *test;

	test = NULL;
	push(&test, 5);
	push(&test, 3);
	push(&test, 14);
	push(&test, 10);
	push(&test, 20);
	ft_printf(1, "value:\n");
	print_stack_2(test);
	normalize_stack(&test);
	ft_printf(1, "\n value:\n");
	print_stack_2(test);
	ft_printf(1, "\n rank:\n");
	print_stack_rank(test);
	free(test);
	return (0);
	
}

void	print_stack_rank(t_stack *target)
{
	while (target != NULL)
	{
		ft_printf(1, "%d ", target->rank);
		target = (target)->next;
	}
}

void	print_stack_2(t_stack *target)
{
	while (target != NULL)
	{
		ft_printf(1, "%d ", target->value);
		target = (target)->next;
	}
}
