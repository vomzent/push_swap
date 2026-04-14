/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:50:50 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/14 12:40:24 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

// void	print_data(t_data *data)
// {
// 	int i;
	
// 	i = 0;
// 	ft_printf(1, "reading t_data:\n");
// 	ft_printf(1, "\n=== data state ===\n");
// 	ft_printf(1, "strategy: %d\n", data->strategy);
// 	ft_printf(1, "benchmark: %d\n", data->benchmark);
// 	ft_printf(1, "length: %d\n", data->length);
// 	ft_printf(1, "args: ");
// 	while (i < data->length)
// 	{
// 		ft_printf(1, "%d ", data->args[i]);
// 		i++;
// 	}
// 	ft_printf(1, "\n\n==================\n");
// }

int	main(int argc, char** argv)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return (error(), 1);
	ft_bzero(data, sizeof(t_data));
	if (argc < 2)
		return (free_data(data), -1);
	if (check_args(argv, data))
		return(error(), free_data(data), 1);
	// print_data(data);
	if (load_data(data))
		return(error(), free_data(data), 1);
	// ft_printf(1, "\nData loaded successfully:\n");
	// print_stack(data->a);
	data->disorder = compute_disorder(data->a);
	sort_stack(data);
	if (data->benchmark)
		benchmark_mode(data);
	// ft_printf(1, "\nData sorted successfully:\n");
	// print_stack(data->a);
	free_data(data);
	return (0);
}
// need to do more research into freeing the data bc now tht i am using malloc for tdata it is a lot more messy
// in parse_input.c i need to do more freeing of data specifically or reroutue it and add freeing in main function

/*
currently having valgrind errors with this, both with check_args and i think also im not passing the d_data *data correctly
when i am saying sort stack it does not sort it in the struct / does not change (i suspect only locally)
*/