/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 08:51:11 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/07 10:27:36 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

double	compute_disorder(t_stack *A)
{
	int	mistakes;
	int	total_pairs;
	float	ret;
	t_stack	*i;
	t_stack	*j;

	mistakes = 0;
	total_pairs = 0;
	i = A;
	j = A->next;
	while (j)
	{
		total_pairs++;
		if (i->value > j->value)
			mistakes++;
		i = i->next;
		j = j->next;
	}
	ft_printf(1, "total_pairs = %d\n", total_pairs);
	ft_printf(1, "mistakes = %d\n", mistakes);
	ret = (double)mistakes / (double)total_pairs;
	return (ret);
}
