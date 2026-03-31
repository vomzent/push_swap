/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_testing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:13:12 by odschreu          #+#    #+#             */
/*   Updated: 2026/03/31 11:30:51 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>

void	print_stack(Stack *target)
{
	while (target->next != NULL)
	{
		ft_printf("%d ", peek(&target));
		target = (target)->next;
	}
}


int	main(void)
{
	Stack	*targetA;
	Stack	*targetB; 
	
	targetA = malloc(sizeof(Stack));
	if (!targetA)
		return (1);
	targetB = malloc(sizeof(Stack));
	if (!targetA)
		return (1);
	push(&targetA, 5);
	push(&targetA, 7);
	push(&targetB, 10);
	push(&targetB, 4);
	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");
	ft_printf("Stack B:\n");
	print_stack(targetB);
	ft_printf("\n");
	// sa/sb checks
	sa(&targetA);
	sb(&targetB);
	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");
	ft_printf("Stack B:\n");
	print_stack(targetB);
	ft_printf("\n");
	// ss check
	ss(&targetA, &targetB);
	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");
	ft_printf("Stack B:\n");
	print_stack(targetB);
	ft_printf("\n");
	// pa/pb checks
	pa(&targetA, &targetB);
	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");
	ft_printf("Stack B:\n");
	print_stack(targetB);
	ft_printf("\n");
	pb(&targetA, &targetB);
	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");
	ft_printf("Stack B:\n");
	print_stack(targetB);
	ft_printf("\n");
	free_stack(&targetA);
	free_stack(&targetB);
	return (0);
}