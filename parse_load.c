/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_load.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 15:38:17 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/14 16:18:45 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	load_data(t_data *data)
{
	int	i;

	if (data->length == 0)
		return (1);
	i = data->length - 1;
	while (i >= 0)
	{
		push(&data->a, data->args[i]);
		if (!data->a)
			return (1);
		i--;
	}
	return (0);
}

void	sort_stack(t_data *data)
{
	double	disorder;

	disorder = compute_disorder(data->a);
	data->disorder = disorder;
	if (data->strategy == 0)
	{
		if (data->disorder < 0.2)
			selection_sort(&data->a, &data->b, data);
		if (data->disorder >= 0.2 && data->disorder < 0.5)
			chunk_sort(data);
		if (data->disorder >= 0.5)
			radix_sort(data);
	}
	else if (data->strategy == 1)
		selection_sort(&data->a, &data->b, data);
	else if (data->strategy == 2)
		chunk_sort(data);
	else if (data->strategy == 3)
		radix_sort(data);
}
