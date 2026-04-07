/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   merge_sort.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: vcoevert <vcoevert@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2026/04/05 16:43:39 by vcoevert     #+#    #+#                  */
/*   Updated: 2026/04/07 21:26:36 by vcoevert     ########   odam.nl          */
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

void	merge_sort(t_stack **a, t_stack **b, size_t len)
{
	t_stack	*ptr;
	t_stack	*mptr;
	t_stack *end;
	size_t	rotate;

	if (len > 2)
	{
		merge_sort(a, b, len / 2);
		rotate = len / 2;
		while (rotate--)
			ra(a);
		merge_sort(a, b, len - len / 2);
		rotate = len / 2;
		while (rotate--)
			rra(a);
	}
	ptr = stack_get(*a, 0);
	mptr = stack_get(*a, len / 2);
	end = stack_get(*a, len);
	while (mptr != end && ptr != mptr)
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
		print_stack(*a);
		ft_printf(1, "\n");
		print_stack(*b);
		ft_printf(1, "\n");
	}
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
	merge_sort(&a, &b, stack_size(a));
	//pb(&a, &b);
	print_stack(a);
	ft_printf(1, "\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
