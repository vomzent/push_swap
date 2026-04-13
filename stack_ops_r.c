/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 08:50:49 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/09 08:31:31 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	ra(t_stack **a, t_data *data)
{
	rotate(a);
	data->ops[5]++;
	data->total_ops++;
	ft_printf(1, "ra\n");
}

void	rb(t_stack **b, t_data *data)
{
	rotate(b);
	data->ops[6]++;
	data->total_ops++;
	ft_printf(1, "rb\n");
}

void	rr(t_stack **a, t_stack **b, t_data *data)
{
	rotate(a);
	rotate(b);
	data->ops[7]++;
	data->total_ops++;
	ft_printf(1, "rr\n");
}
