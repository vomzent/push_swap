/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:25:09 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/14 12:44:44 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

int	check_args(char **argv, t_data *data)
{
	char	**no_flags;
	char	**tmp;
	int		i;

	i = 0;
	no_flags = NULL;
	if (assign_flags(argv, data))
		return (1);
	no_flags = parse_flags(argv);
	if (!no_flags)
		return (1);
	if (no_flags[1] == NULL)
	{
		tmp = no_flags;
		no_flags = ft_split(no_flags[0], ' ');
		free_array((void **)tmp);
	}
	// while (no_flags[i])
	// 	ft_printf(1, "%s\n", no_flags[i++]);
	if (validate_strings(no_flags))
		return (free_array((void **)no_flags), 1);
	if (convert_str(no_flags, data))
		return (free_array((void **)no_flags), 1);
	return (free_array((void **)no_flags), 0);
}

int	assign_flags(char **argv, t_data *data)
{
	int	i;
	int	strategy;

	strategy = 0;
	i = count_flags(argv);
	if (i == -1)
		return (1);
	while (i > 0)
	{
		if (ft_strcmp(argv[i], "--bench"))
		{
			strategy++;
			if (strategy > 1)
				return (1);
			data->strategy = check_strategy(argv[i]);
			if (data->strategy == -1)
				return (1);
		}
		else
			data->benchmark = 1;
		i--;
	}
	return (0);
}

int	count_flags(char **argv)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (argv[i])
	{
		if (argv[i][1] == '-')
			count++;
		i++;
	}
	if (count > 2)
		return (-1);
	return (count);
}

char	**parse_flags(char **argv)
{
	char	**no_flags;
	int		i;
	int		j;

	no_flags = (char **)malloc(sizeof(char *) * (count_args(argv) + 1));
	ft_bzero(no_flags, sizeof(char *) * (count_args(argv) + 1));
	i = 1;
	j = 0;
	while (argv[i])
	{
		if (argv[i][1] != '-')
		{
			no_flags[j] = ft_strdup(argv[i]);
			j++;
		}
		i++;
	}
	if (i - j > 3)
	{
		free_array((void **)no_flags);
		return (NULL);
	}
	return (no_flags);
}
		// if ((argv[i][0] == ' ' || ft_isdigit(argv[i][0])
		// 	|| argv[i][0] == '-' || argv[i][0] == '+')
		// 	&& argv[i][1] != '-')




int	count_args(char **argv)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (argv[i])
	{
		if (argv[i][1] == '-')
			i++;
		count++;
		i++;
	}
	return (count);
}
