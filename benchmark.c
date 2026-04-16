/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   benchmark.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/04 09:48:42 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/16 10:52:04 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	benchmark_mode(t_data *data)
{
	char	*strategy;

	strategy = set_strategy(data);
	ft_printf(2, "[bench] disorder: %.%%\n", data->disorder);
	ft_printf(2, "[bench] strategy: %s\n", strategy);
	ft_printf(2, "[bench] total_ops: %d\n", data->total_ops);
	ft_printf(2, "[bench] sa: %d ", data->ops[0]);
	ft_printf(2, "sb: %d ", data->ops[1]);
	ft_printf(2, "ss: %d ", data->ops[2]);
	ft_printf(2, "pa: %d ", data->ops[3]);
	ft_printf(2, "pb: %d\n", data->ops[4]);
	ft_printf(2, "[bench] ra: %d ", data->ops[5]);
	ft_printf(2, "rb: %d ", data->ops[6]);
	ft_printf(2, "rr: %d ", data->ops[7]);
	ft_printf(2, "rra: %d ", data->ops[8]);
	ft_printf(2, "rrb: %d ", data->ops[9]);
	ft_printf(2, "rrr: %d\n", data->ops[10]);
}

char	*set_strategy(t_data *data)
{
	char	*strategy_str;

	if (data->strategy == 0)
		strategy_str = adaptive_strategy(data->disorder);
	if (data->strategy == 1)
		strategy_str = "Simple / O(n^2)";
	if (data->strategy == 2)
		strategy_str = "Medium / O(n√n)";
	if (data->strategy == 3)
		strategy_str = "Complex / O(n log n)";
	return (strategy_str);
}

char	*adaptive_strategy(double disorder)
{
	if (disorder < 0.2)
		return ("Adaptive / O(n^2)");
	else if (disorder >= 0.2 && disorder < 0.5)
		return ("Adaptive / O(n√n)");
	else if (disorder >= 0.5)
		return ("Adaptive / O(n log n)");
	return ("Error\n");
}
