/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vcoevert <vcoevert@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/13 17:29:10 by vcoevert      #+#    #+#                 */
/*   Updated: 2026/04/16 10:47:06 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "checker.h"
#include <stdlib.h>

char	**prepare_arg(int argc, char **argv)
{
	char	**ret;
	int		i;

	i = 0;
	if (argc == 2)
		ret = ft_split(argv[1], ' ');
	else
	{
		ret = malloc(sizeof(char *) * argc);
		if (ret)
		{
			ft_bzero(ret, sizeof(char *) * argc);
			while (++i < argc)
			{
				ret[i - 1] = ft_strdup(argv[i]);
				if (!ret[i - 1])
					return (free_array((void **)ret), (char **)0);
			}
		}
	}
	if (ret)
		if (validate_strings(ret))
			return (free_array((void **)ret), (char **)0);
	return (ret);
}

int	go_through_stdin(t_data *data)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (!perform_operation_1(data, str) && !perform_operation_2(data, str))
			return (free(str), 1);
		free(str);
		str = get_next_line(0);
	}
	return (0);
}

int	load_data(t_data *data)
{
	int	i;

	if (data->length == 0)
		return (1);
	i = data->length - 1;
	while (i >= 0)
	{
		push(&data->a, data->args[i]);
		if (!data->a)
			return (1);
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**arg;

	if (argc < 2)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_printf(2, "Error\n"), -1);
	ft_bzero(data, sizeof(t_data));
	arg = prepare_arg(argc, argv);
	if (!arg)
		return (free_data(data), ft_printf(2, "Error\n", -1));
	if (convert_str(arg, data) || load_data(data))
		return (free_data(data), free_array((void **)arg),
			ft_printf(2, "Error\n"), -1);
	if (go_through_stdin(data))
		return (free_data(data), free_array((void **)arg),
			ft_printf(2, "Error\n"), -1);
	if (is_stack_sorted(data->a) && !data->b)
		ft_printf(1, "OK\n", 0);
	else
		ft_printf(1, "KO\n", 0);
	free_data(data);
	free_array((void **)arg);
	return (0);
}
