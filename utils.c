/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 10:47:14 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/13 18:49:29 by odschreu         ###   ########.fr       */
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

void	free_array(void **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int	array_size(char	**arg)
{
	int	i;

	i = 0;
	while (arg[i] != NULL)
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
