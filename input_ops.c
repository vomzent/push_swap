/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:25:09 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/07 10:26:44 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char** argv)
{
	Data	data;
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

char	**parse_flags(char **argv, int *strategy, int *benchmark)
{
	char	**no_flags;

	no_flags = (char **)malloc(sizeof(*noflags) * count_args(argv) + 1);
	ft_bzero(no_flags);
	while (argv[i])
	{
		if  
	}
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

/*
1. parse flags (-- bench -- adaptive), strip them from argv -> create/malloc new array
2. validate strings
3. convert to long check range
4. check duplicates (in int array)
5. load into stack
6. run sorting algo based on data->stratey
7. run benchmark mode always, print benchmark mode if data->benchmark == 1
*/

