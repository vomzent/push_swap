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
#include <stdio.h>
#include <stdlib.h>

void	print_stack(Stack *target)
{
	while (target != NULL)
	{
		ft_printf("%d ", target->value);
		target = (target)->next;
	}
}


int	main(void)
{
	Stack	*targetA = NULL;
	Stack	*targetB = NULL;
	Stack	*targetC = NULL;
	
	// targetA = malloc(sizeof(Stack));
	// if (!targetA)
	// 	return (1);
	// targetB = malloc(sizeof(Stack));
	// if (!targetA)
	// 	return (1);
	push(&targetA, 5);
	push(&targetA, 7);
	push(&targetA, 4);
	push(&targetA, 3);
	push(&targetA, 1);
	push(&targetB, 10);
	push(&targetB, 7);
	push(&targetB, 5);
	push(&targetB, 4);
	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");
	ft_printf("Stack B:\n");
	print_stack(targetB);
	ft_printf("\n");
	printf("Stack A disorder = %lf\n", compute_disorder(targetA));
	printf("Stack B disorder = %lf\n", compute_disorder(targetB));
	//
	ra(&targetA);
	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");
	rb(&targetB);
	ft_printf("Stack B:\n");
	print_stack(targetB);
	ft_printf("\n");
	rr(&targetA, &targetB);
	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");
	ft_printf("Stack B:\n");
	print_stack(targetB);
	ft_printf("\n");
	ft_printf("Selection sort \n")
	selection_sort(&targetA, &targetC);
	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");
	ft_printf("Stack C:\n");
	print_stack(targetC);
	ft_printf("\n");
	free_stack(&targetA);
	free_stack(&targetB);
	free_stack(&targetC);
	return (0);
}