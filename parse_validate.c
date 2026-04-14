/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:38:23 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/14 12:16:15 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <limits.h>

int	check_strategy(char *argv)
{
	int	strategy;

	strategy = -1;
	if (ft_strcmp(argv, "--adaptive") == 0)
		return (0);
	if (ft_strcmp(argv, "--simple") == 0)
		return (1);
	if (ft_strcmp(argv, "--medium") == 0)
		return (2);
	if (ft_strcmp(argv, "--complex") == 0)
		return (3);
	return (strategy);
}

int	validate_strings(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (invalid_string(array[i]))
			return (1);
		i++;
	}
	return (0);
}

int	invalid_string(char *string)
{
	int	i;

	i = 0;
	if (string[0] == '-')
		i++;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			return (1);
		i++;
	}
	return (0);
}

int	convert_str(char **array, t_data *data)
{
	long	n;
	int		*ret;
	int		array_len;
	int		i;

	n = 0;
	i = 0;
	array_len = array_size(array);
	ret = (int *)malloc(sizeof(int) * array_len);
	while (array[i])
	{
		n = ft_atol(array[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (free(ret), 1);
		ret[i] = (int)n;
		i++;
	}
	if (check_duplicates(ret, array_len))
		return (free(ret), 1);
	data->length = array_len;
	data->args = ret;
	return (0);
}

int	check_duplicates(int *array, int array_len)
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < array_len)
	{
		j = i + 1;
		while (j < array_len)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
