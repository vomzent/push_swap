/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 09:48:42 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/04 12:15:35 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	benchmark_mode(Data *data)
{
	char	*strategy;

	strategy = set_strategy(data->strategy, data->disorder);
	ft_printf(2, "disorder: %.%%\n", data->disorder);
	ft_printf(2, "%s\n", strategy);
	ft_printf(2, "total_ops: %d\n", data->total_ops);
	ft_printf(2, "sa: %d ", data->ops[0]);
	ft_printf(2, "sb: %d ", data->ops[1]);
	ft_printf(2, "ss: %d ", data->ops[2]);
	ft_printf(2, "pa: %d ", data->ops[3]);
	ft_printf(2, "pb: %d\n", data->ops[4]);
	ft_printf(2, "ra: %d ", data->ops[5]);
	ft_printf(2, "rb: %d ", data->ops[6]);
	ft_printf(2, "rr: %d ", data->ops[7]);
	ft_printf(2, "rra: %d ", data->ops[8]);
	ft_printf(2, "rrb: %d ", data->ops[9]);
	ft_printf(2, "rrr: %d\n", data->ops[10]);
}

char	*set_strategy(int strategy, double disorder)
{
	if (data->strategy == 0)
		strategy = adaptive_strategy(disorder);
	if (data->strategy == 1)
		strategy = "Simple / O(n^2)";
	if (data->strategy == 2)
		strategy = "Medium / O(n√n)";
	if (data->strategy == 3)
		strategy = "Complex / O(n log n)";
}

char	*adaptive_strategy(double disorder)
{
	if (disorder < 0.2)
		return ("Adaptive / O(n^2)");
	else if (disorder >= 0.2 && disorder < 0.5)
		return ("Adaptive / O(n√n)");
	else if (disorder >= 0.5)
		return ("Adaptive / O(n log n)");
}
