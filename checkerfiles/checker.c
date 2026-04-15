/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   checker.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/13 17:29:10 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/04/15 13:35:48 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include "checker.h"
#include <stdlib.h>

int	perform_operation(t_data *data, char *op)
{
	if (!ft_strcmp(op, "sa\n"))
		swap(&data->a);
	else if (!ft_strcmp(op, "sb\n"))
		swap(&data->b);
	else if (!ft_strcmp(op, "ss\n"))
	{
		swap(&data->a);
		swap(&data->b);
	}
	else if (!ft_strcmp(op, "pa\n"))
		np_pa(&data->a, &data->b);
	else if (!ft_strcmp(op, "pb\n"))
		np_pb(&data->a, &data->b);
	else if (!ft_strcmp(op, "ra\n"))
		rotate(&data->a);
	else if (!ft_strcmp(op, "rb\n"))
		rotate(&data->b);
	else if (!ft_strcmp(op, "rr\n"))
	{
		rotate(&data->a);
		rotate(&data->b);
	}
	else if (!ft_strcmp(op, "rra\n"))
		reverse_rotate(&data->a);
	else if (!ft_strcmp(op, "rrb\n"))
		reverse_rotate(&data->b);
	else if (!ft_strcmp(op, "rrr\n"))
	{
		reverse_rotate(&data->a);
		reverse_rotate(&data->b);
	}
	else
		return (0);
	return (1);
}

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
		if (!perform_operation(data, str))
			return (1);
		free(str);
		str = get_next_line(0);
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
		return (ft_printf(1, "Error\n"), -1);
	ft_bzero(data, sizeof(data));
	arg = prepare_arg(argc, argv);
	if (!arg)
		return (free_data(data), ft_printf(1, "Error\n", -1));
	if (convert_str(arg, data) || load_data(data))
		return (free_data(data), free_array((void **)arg), ft_printf(1, "Error\n"), -1);
	if (go_through_stdin(data))
		return (free_data(data), free_array((void **)arg), ft_printf(1, "Error\n"), -1);
	if (is_stack_sorted(data->a) && !data->b)
		ft_printf(1, "OK", 0);
	else
		ft_printf(1, "KO", 0);
	free_data(data);
	free_array((void **)arg);
	return (0);
}
