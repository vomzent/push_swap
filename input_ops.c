/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:25:09 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/07 10:44:26 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

/*
1. parse flags (-- bench -- adaptive), strip them from argv -> create/malloc new array
2. validate strings
3. convert to long check range
4. check duplicates (in int array)
5. load into stack
6. run sorting algo based on data->stratey
7. run benchmark mode always, print benchmark mode if data->benchmark == 1
*/


int	main(int argc, char** argv)
{
	t_data	data;
	char	**args;
	
	if (argc < 2)
		return (-1);
	ft_bzero(&data, sizeof(data));
	args = extract_arg(argc, argv);
	if (!check_args)
	{
		ft_printf("Error\n");
		return (0);
	}
	sort_stack(&data->A, &data->B, data->strategy);
	benchmark_mode(&data);
	free(data);
	return (0);
}

int	check_args(char **argv, *data)
{
	char	**no_flags;

	no_flags = parse_flags(argv);
	if (!no_flags)
		return (error(), 1);
	if (!validate_strings(no_flags))
	{
		error();
		return (free(no_flags), 1);
	}
	
	return (free(no_flags), 0);
	
}

int	validate_strings(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (check_string(array[i]))
			return (1);
	}
	return (0);
}

int	check_string(char *string)
{
	int	i;

	i = 0;
	if (string[i] == "-")
		i++;
	while (string[i])
	{
		if (!ft_isdigit(string[i] - 30))
			return (1);
		i++;
	}
	return (0);
}

char	**parse_flags(char **argv, int *strategy, int *benchmark)
{
	char	**no_flags;
	int		i;
	int		j;

	no_flags = (char **)malloc(sizeof(*noflags) * count_args(argv) + 1);
	ft_bzero(no_flags);
	i = 0;
	j = 0;
	while (argv[i])
	{
		if (argv[i][1] == "-")
			continue ;
		else
		{
			no_flags[j] = ft_strdup[argv[i]];
			j++;
		}
		i++;
	}
	if (i - j > 2)
	{
		free(no_flags);
		return ((error(), NULL));
	}
	return (no_flags);
}

int	count_args(char **argv)
{
	int	count;
	int i;
	
	i = 1;
	while (argv[i])
	{
		if (argv[i][1] == "-")
			i++;
		count++;
		i++;
	}
	return (count);
}

void	error(void)
{
	ft_printf("Error\n");
	return ;
}


