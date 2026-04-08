/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:25:09 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/08 11:00:35 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

/*
1. parse flags (-- bench -- adaptive), strip them from argv -> create/malloc new array (parse_flags)
2. validate strings (validatestrings)
3. convert to long check range 
4. check duplicates (in int array) (check_duplicates)
5. load into stack (load_data -> both to push int array)
6. run sorting algo based on data->stratey
7. run benchmark mode always, print benchmark mode if data->benchmark == 1
*/

int	main(int argc, char** argv)
{
	t_data	data;
	
	if (argc < 2)
		return (-1);
	ft_bzero(&data, sizeof(data));
	if (check_args)
		return(error(), 1);
	if (load_data(&data))
		return(error(), 1);
	sort_stack(&data->A, &data->B, data->strategy);
	benchmark_mode(data);
	free(data);
	return (0);
}

int	check_args(char **argv, t_data *data)
{
	char	**no_flags;
	char	**tmp;
	int		*arguments;

	no_flags = parse_flags(argv);
	if (!no_flags)
		return (1);
	if (no_flags[1] == NULL)
	{
		tmp = no_flags;
		no_flags = ft_split(no_flags[0], " ");
		free(tmp);
	}
	if (validate_strings(no_flags))
		return (free(no_flags), 1);
	if (convert_arg(no_flags, data))
		return (free(no_flags), 1);
	if (assign_flags(argv, data))
		return (free(no_flags), 1);
	return (free(no_flags), 0);
}

int	load_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->length)
	{
		push(&data->A, data->args[i]);
		i++;
	}
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
		if (ft_strncmp(argv[i], "--bench"))
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

	count = 0;
	while (argv[i])
	{
		if (argv[i][1] == "-")
			count++;
		i++;
	}
	if (count > 2)
		return (-1);
	return (count);
}

int	convert_arg(char **array, t_data *data)
{
	long	n;
	int		*ret;
	int		array_len;
	
	n = 0;
	i = 0;
	array_len = array_size(array);
	ret = (int *)malloc(sizeof(int) * array_len - 1);
	while (array[i])
	{
		n = ft_atol(array[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (free(ret), 1);
		ret[i] = (int)n;
		i++;
	}
	if (check_duplicates(ret, array_len));
		return (1);
	data->length = array_len;
	data->args = ret;
	return (free(ret), 0);
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

	no_flags = (char **)malloc(sizeof(char *) * count_args(argv) + 1);
	ft_bzero(no_flags);
	i = 0;
	j = 0;
	while (argv[i])
	{
		// make sure to check no segfault for 1 variable
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
		return (NULL);
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

int	check_strategy(char *argv)
{
	int	i;
	int	strategy;

	i = 1;
	strategy = -1;
	while (argv)
	{
		if (ft_strcmp(argv, "--adaptive") == 0)
			return (0);
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
		n--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	sort_stack(t_stack **A, t_stack **B, int strategy)
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
