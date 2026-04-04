/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 08:51:22 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/04 11:18:42 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char** argv)
{
	Data	data;
	int		strategy;
	
	if (argc < 2)
		return (-1);
	ft_bzero(&data, sizeof(data));
	strategy = extract_arg(argc, argv, A);
	if (strategy == -1)
		return (-1);
	sort_stack(A, B, strategy);
	benchmark_mode(&data);
	free(data);
	return (0);
}

// check for errors: args that are not int, integers outside of valid range, duplicates

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
			while(arg[i])
				convert_push(A, arg[i++]);
		}
		else
			convert_push(A, argv);
		i++;
	}
	return (strategy);
}

void	convert_push(Stack **A, char	*arg)
{
	int	number;

	number = ft_atoi(arg);
	push(A, number);
}


int	check_strategy(int argc, char **argv)
{
	int	i;
	int	strategy;

	i = 1;
	strategy = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			return (1);
		if (ft_strcmp(argv[i], "--medium") == 0)
			return (2);
		if (ft_strcmp(argv[i], "--complex") == 0)
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