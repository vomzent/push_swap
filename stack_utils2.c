// header

#include "push_swap.h"

int	retrieve_pos(t_stack *a, int found)
{
	int	pos;
	int	counter;

	counter = 0;
	pos = 0;
	while (a)
	{
		if (a->value == found)
		{
			pos = counter;
			break;
		}
		counter++;
		a = a->next;
	}
	return (pos);
}
