// the functions that did not make it...

void	extract_max(Stack **A, Stack **B)
{
	int	max;
	int	size;

	if (!*A)	
	{
		ft_printf("Error\n");
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