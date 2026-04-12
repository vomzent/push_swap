// header

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stddef.h>

void	swap(t_stack **a)
{
	t_stack	*tmp;
	
	if ((*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

void	push(t_stack **target, int value)
{
	t_stack	*node;
	
	if (*target == NULL)
	{
		*target = malloc(sizeof(t_stack));
		if (!*target)
			return ;
		ft_bzero(*target, sizeof(t_stack));
		(*target)->value = value;
		// (*target)->rank = -1;
		return ;
	}
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	ft_bzero(node, sizeof(t_stack));
	// node->rank = -1;
	node->value = value;
	node->next = *target;
	(*target)->previous = node;
	*target = node;
}

int	pop(t_stack **target)
{
	int		popped;
	t_stack	*tmp;

	if (!(*target))
		return (0);
	popped = (*target)->value;
	tmp = (*target)->next;
	free(*target);
	*target = tmp;
	if (*target)
		(*target)->previous = NULL;
	return (popped);
}

int	peek(t_stack **target)
{
	int	peek;

	peek = 0;
	if ((*target)->value == 0)
		ft_printf(1, "Error\n");
	else
		peek = (*target)->value;
	return (peek);
}

void	rotate(t_stack **a)
{
	t_stack	*head;

	head = *a;
	while (head->next != 0)
		head = head->next;
	head->next = *a;
	*a = (*a)->next;
	head->next->next = NULL;
}
