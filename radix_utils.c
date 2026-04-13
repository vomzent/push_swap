/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:37:28 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/13 18:34:03 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// retrieve i-th bit 
// (rotate in a, push to b, then once all 0 bits of that index are retrieved, push back to a)

// 1. retrieve all 0s from the right most position, push to b, then push back to a
// 2. repeat loop / function for all positions / indexes -- how to know how many bits to scan / push?
// 3. after last loop the stack in a is sorted (so after pushing it back from b to a after retrieving the bits where 0 is hte left most bit)

// int retrieve max bits function
// 

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

