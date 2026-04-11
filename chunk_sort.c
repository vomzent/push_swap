// header

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

void	chunk_sort(t_stack **a, t_stack **b, t_data *data)
{
	int	i;
	int	**chunks;

	i = 0;
	chunks = create_chunks(stack_size(*a));
	while (chunks[i])
	{
		retrieve_chunk(a, b, data, chunks[i]);
		ft_printf(1, "chunk %d retrieved\n", i);
		i++;
	}
	retrieve_max(a, b, data);
	free(chunks);
}

int	main(void)
{
	t_stack *test = NULL;
	t_stack *test2 = NULL;
	int		i;
	int		**chunks = NULL;\
	t_data	*data;
	data = malloc(sizeof(t_data));
	ft_bzero(data, sizeof(t_data));

	i = 0;
	push(&test, 15);
	push(&test, -3);
	push(&test, 8);
	push(&test, -17);
	push(&test, 12);
	push(&test, -8);
	push(&test, 20);
	push(&test, -1);
	push(&test, 5);
	push(&test, -14);
	push(&test, 18);
	push(&test, -6);
	push(&test, 3);
	push(&test, -19);
	push(&test, 11);
	push(&test, -2);
	push(&test, 7);
	push(&test, -11);
	push(&test, 16);
	push(&test, -9);
	chunks = create_chunks(stack_size(test));
	while (chunks[i])
	{
		ft_printf(1, "[%d, %d], ", chunks[i][0], chunks[i][1]);
		i++;
	}
	ft_printf(1, "value:\n");
	print_stack_2(test);
	normalize_stack(&test);
	ft_printf(1, "\n value:\n");
	print_stack_2(test);
	ft_printf(1, "\n rank:\n");
	print_stack_rank(test);
	ft_printf(1, "\nData loaded successfully:\n");
	print_stack(test);
	chunk_sort(&test, &test2, data);
	ft_printf(1, "\nData sorted successfully:\n");
	print_stack(test);
	ft_printf(1, "\n");
	free(test);
	free_data(data);
	return (0);
	
}

void	print_stack_2(t_stack *target)
{
	while (target != NULL)
	{
		ft_printf(1, "%d ", target->value);
		target = (target)->next;
	}
}