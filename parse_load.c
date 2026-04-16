/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_load.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 15:38:17 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/16 10:53:05 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (error(), 1);
	ft_bzero(data, sizeof(t_data));
	if (argc < 2)
		return (free_data(data), -1);
	if (check_args(argv, data))
		return (error(), free_data(data), 1);
	if (load_data(data))
		return (error(), free_data(data), 1);
	data->disorder = compute_disorder(data->a);
	sort_stack(data);
	if (data->benchmark)
		benchmark_mode(data);
	free_data(data);
	return (0);
}

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
