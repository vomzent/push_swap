/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:25:09 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/07 11:19:22 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

/*
1. parse flags (-- bench -- adaptive), strip them from argv -> create/malloc new array (parse_flags)
2. validate strings (validatestrings)
3. convert to long check range 
4. check duplicates (in int array) (check_duplicates)
5. load into stack (load_data -> both to push int array AND define strategy/benchmark)
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
	if (check_args)
		return(error(), 1);
	
	sort_stack(&data->A, &data->B, data->strategy);
	benchmark_mode(&data);
	free(data);
	return (0);
}

int	conversion

int	check_args(char **argv, *data)
{
	char	**no_flags;

	no_flags = parse_flags(argv);
	if (!no_flags)
		return (error(), 1);
	if (validate_strings(no_flags))
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
		if (invalid_input(array[i]))
			return (1);
		i++;
	}
	return (0);
}

int	invalid_input(char *string)
{
	int	i;

	i = 0;
	if (string[0] == "-")
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
	ft_printf(1, "Error\n");
	return ;
}


