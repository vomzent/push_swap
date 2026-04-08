/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:50:50 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/08 14:13:22 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

void	print_data(t_data *data)
{
	int i;
	
	i = 0;
	ft_printf(1, "reading t_data:\n");
	ft_printf(1, "\n=== data state ===\n");
	ft_printf(1, "strategy: %d\n", data->strategy);
	ft_printf(1, "benchmark: %d\n", data->benchmark);
	ft_printf(1, "length: %d\n", data->length);
	ft_printf(1, "args: ");
	while (i < data->length)
	{
		ft_printf(1, "%d ", data->args[i]);
		i++;
	}
	ft_printf(1, "\n\n==================\n");
}

int	main(int argc, char** argv)
{
	t_data	data;
	
	if (argc < 2)
		return (-1);
	ft_bzero(&data, sizeof(t_data));
	if (check_args(argv, &data))
		return(error(), 1);
	print_data(&data);
	if (load_data(&data))
		return(error(), 1);
	ft_printf(1, "\nData loaded successfully:\n");
	print_stack(data.A);
	// sort_stack(&data, data.strategy);
	// benchmark_mode(&data);
	return (0);
}