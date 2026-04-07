/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redundant_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 08:50:59 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/07 10:49:53 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void	extract_max(t_stack **A, t_stack **B)
{
	int	max;
	int	size;

	if (!*A)	
	{
		ft_printf(1, "Error\n");
		return ;
	}
	max = find_max(*A);
	size = stack_size(*A);
	while (size + 1 > 0)
	{
		if ((*A)->value != max)
		{
			pb(A, B);
		}
		else
			*A = (*A)->next;
		size--;
	}
	push(A, max);
}