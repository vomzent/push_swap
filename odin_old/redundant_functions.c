/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   redundant_functions.c                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: odschreu <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
q
/*   Created: 2026/04/14 15:18:37 by odschreu       #+#    #+#                */
/*   Updated: 2026/04/14 15:18:37 by odschreu       ########   odam.nl        */
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
