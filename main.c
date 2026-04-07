/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 08:51:22 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/07 10:23:05 by odschreu         ###   ########.fr       */
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

	no_flags = (char **)malloc(sizeof(*noflags) * array_size(argv) + 1);
	ft_bzero(no_flags);
	while (argv[i])
	{
		if  
	}
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

// check for errors: args that are not int, integers outside of valid range, duplicates


char	**extract_arg(int argc, char **argv)
{
	int		i;
	int		j;
	char	**args;
	char	**arg;
	
	i = 1;
	while (argv[i])
	{
		arg = ft_split(argv[i]);
		if (!arg)
			return (NULL);
		if (!arg[1])
		{
			if (!args)
				args = arg;
			else
				args = append_arg(arg, args);
			if (!args)
				return (NULL);
		}
		free(arg);
		i++;
	}
	return (args);
}

int	array_size(char	**arg)
{
	int	i;
	
	i = 0;
	while (arg[i] != NULL)
		i++;
	return (i);
}

void	append_arg(char **arg, char **args)
{
	char	**updated_arr;

	updated_arr = (char **)malloc(array_size(args) + array_size(arg) + 1) * sizeof(*updated_arr);
	while (args[i])
	{
		updated_arr[i] = ft_strdup(args[i]);
		i++;
	}
	while (arg[j])
	{
		updated_arr[i] = ft_strdup(arg[j]);
		j++;
	}
	free(args);
	return (updated_arr);
}

int	*convert_args(char **args)
{
	int		i;
	int		*array;
	long	n;
	
	i = 0;
	array = (int *)malloc(sizeof(int) * int_array_size(args));
	while (args[i])
	{
		if (args[i][1] == "-" && i < 2)
			i++;
		if (!ft_isdigit(args[i][1] - 30))
		{
			free(array);
			return (error(), 0);
		}
		n = ft_atol(args[i])
		if (n > INT_MAX || n < INT_MIN)
		{
			return (error(), 0);
			free(array);
		}
		array[i] = (int)n; 
		i++;
	}
	return (array);
}

void	error(void)
{
	ft_printf("Error\n");
	return ;
}

int	int_array_size(char **args)
{
	int	count;

	count = 0;
	while (args[i])
	{
		if (args[i][0] == "-")
			i++;
		count++;
		i++;
	}
	return (count);
}

// ptr_array = (char **)malloc((token_count + 1) * sizeof(*ptr_array));

int	extract_arg(int argc, char **argv, Stack **A)
{
	int		i;
	int		j;
	int		strategy;
	char	**arg;

	if (check_error(argv))
	{
		ft_printf("Error\n");
		return(-1);
	}
	strategy = check_strategy(argc, argv);
	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
		{
			i++;
			j = 0;
		}
		while (ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j] == ' ')
		{
			arg = ft_split(argv[i]);
			check_arg(arg);
			while(arg[i])
				convert_arg(arg[i++]);
		}
		if 
			convert_push(A, argv);
		i++;
	}
	return (strategy);
}

void	convert_arg(char *arg)
{
	int	number;

	number = ft_atoi(arg);
	push(A, number);
}


int	check_strategy(char *argv)
{
	int	i;
	int	strategy;

	i = 1;
	strategy = 0;
	while (argv)
	{
		if (ft_strcmp(argv, "--simple") == 0)
			return (1);
		if (ft_strcmp(argv, "--medium") == 0)
			return (2);
		if (ft_strcmp(argv, "--complex") == 0)
			return (3);
		i++;
	}
	return (strategy);
}

// libft only has ft_strncmp so again i really feel like we should just rewrite it to strcmp
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	sort_stack(Stack **A, Stack **B, int strategy)
{
	double	disorder;

	disorder = compute_disorder(*A);
	if (strategy == 1)
		selection_sort(A, B);
	else if (strategy == 2)
		chunk_sort(A, B);
	else if (strategy == 3)
		quick_sort(A, B);
	else
		adaptive_sort(A, B, disorder);
}

/// bench.txt