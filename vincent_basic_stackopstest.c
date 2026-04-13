/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   vincent_basic_stackopstest.c                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/05 16:43:39 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/04/07 20:19:10 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

t_stack	*stack_get(t_stack *s, size_t index)
{
	index++;
	while (--index && s)
		s = s->next;
	return (s);
}
void	sort_stack(t_stack **a, t_stack **b)
{
	size_t	len;
	t_stack	*ptr;
	t_stack	*mptr;

	len = stack_size(*a);
	ptr = stack_get(*a, 0);
	mptr = stack_get(*a, len / 2);
	while (len && ptr && mptr && ptr != mptr)
	{
		if (ptr->value < mptr->value)
		{
			while (*a != ptr)
				rra(a);
			ptr = ptr->next;
			pb(a, b);
		}
		else
		{
			while (*a != mptr)
				ra(a);
			mptr = mptr->next;
			pb(a, b);
		}
		--len;
		print_stack(*a);
		ft_printf(1, "\n");
		print_stack(*b);
		ft_printf(1, "\n");
	}
	while (len--)
		pb(a, b);
	while (*b)
		pa(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = 0;
	b = 0;
	if (argc < 2)
		return (0);
	i = 1;
	while (++i <= argc)
		push(&a, argv[i - 1][0] - '0');
	print_stack(a);
	ft_printf(1, "\n");
	// ft_printf(1, "%d", stack_size(a));
	sort_stack(&a, &b);
	//pb(&a, &b);
	print_stack(a);
	ft_printf(1, "\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
