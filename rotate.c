//header


#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stddef.h>

void	np_ra(Stack **A)
{
	Stack	*head;

	head = *A;
	while (head->next != 0)
		head = head->next;
	head->next = *A;
	*A = (*A)->next;
	head->next->next = NULL;
}

void	np_rb(Stack **B)
{
	Stack	*head;

	head = *B;
	while (head->next != 0)
		head = head->next;
	head->next = *B;
	*B = (*B)->next;
	head->next->next = NULL;
}

void	ra(Stack **A)
{
	np_ra(A);
	ft_printf("ra\n");
}

void	rb(Stack **B)
{
	np_rb(B);
	ft_printf("rb\n");
}

void	rr(Stack **A, Stack **B)
{
	np_ra(A);
	np_rb(B);
	ft_printf("rr\n");
}
