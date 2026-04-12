/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:25:09 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/09 11:25:49 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

/*
1. parse flags (-- bench -- adaptive), strip them from argv -> create/malloc new array (parse_flags)
2. validate strings (validatestrings)
3. convert to long check range 
4. check duplicates (in int array) (check_duplicates)
5. load into stack (load_data -> both to push int array)
6. run sorting algo based on data->stratey
7. run benchmark mode always(?), print benchmark mode if data->benchmark == 1
*/

int	check_args(char **argv, t_data *data)
{
	char	**no_flags;
	char	**tmp;

	no_flags = NULL;
	ft_printf(1, "\n entering assign flags\n");
	if (assign_flags(argv, data))
		return (1);
	ft_printf(1, "\n entering parse flags\n");
	no_flags = parse_flags(argv);
	if (!no_flags)
		return (1);
	if (no_flags[1] == NULL)
	{
		tmp = no_flags;
		no_flags = ft_split(no_flags[0], ' ');
		free(tmp);
	}
	ft_printf(1, "\n entering valid strings\n");
	if (validate_strings(no_flags))
		return (free_data(data), free_array(no_flags), 1);
	ft_printf(1, "\n entering convert strings\n");
	if (convert_str(no_flags, data))
		return (free_data(data), free_array(no_flags), 1);
	return (0);
}

int	assign_flags(char **argv, t_data *data)
{
	int	i;

	i = count_flags(argv);
	if (i == -1)
		return (1);
	while (i > 0)
	{
		if (ft_strcmp(argv[i], "--bench"))
		{
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
		// make sure to check no segfault for 1 variable
		if ((argv[i][0] == ' ' || ft_isdigit(argv[i][0])
			|| argv[i][0] == '-') && argv[i][1] != '-')
		{
			no_flags[j] = ft_strdup(argv[i]);
			j++;
		}
		i++;
	}
	if (i - j > 3)
	{
		free_array(no_flags);
		return (NULL);
	}
	return (no_flags);
}

int	count_args(char **argv)
{
	int	count;
	int i;
	
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

