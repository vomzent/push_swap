/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 10:47:14 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/09 11:09:21 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_stack(&data->a);
	free_stack(&data->b);
	if (data->args)
		free(data->args);
	free(data);
}

void	error(void)
{
	ft_printf(1, "Error\n");
	return ;
}

void	free_arrays(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
