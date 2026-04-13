// header

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

void	chunk_sort(t_data *data)
{
	int	i;
	int	**chunks;

	normalize_stack(&data->a);
	i = 0;
	chunks = create_chunks(stack_size(data->a));
	while (chunks[i])
	{
		retrieve_chunk(&data->a, &data->b, data, chunks[i]);
		i++;
	}
	retrieve_max(&data->a, &data->b, data);
	free(chunks);
}

void	radix_sort(t_data *data)
{
	data->disorder = 1;
	return ;
}