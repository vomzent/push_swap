/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 15:37:28 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/16 10:53:43 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int stack_size)
{
	int	bits;
	int	max;

	bits = 0;
	max = stack_size - 1;
	while (max > 0)
	{
		bits++;
		max = max >> 1;
	}
	return (bits);
}
