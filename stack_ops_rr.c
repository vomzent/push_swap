/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:32:53 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/09 08:31:37 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	rra(t_stack **a, t_data *data)
{
	reverse_rotate(a);
	data->ops[8]++;
	data->total_ops++;
	ft_printf(1, "rra\n");
}

void	rrb(t_stack **b, t_data *data)
{
	reverse_rotate(b);
	data->ops[9]++;
	data->total_ops++;
	ft_printf(1, "rrb\n");
}

void	rrr(t_stack **a, t_stack **b, t_data *data)
{
	reverse_rotate(a);
	reverse_rotate(b);
	data->ops[10]++;
	data->total_ops++;
	ft_printf(1, "rrr\n");

}
