// header

#include "push_swap.h"

int	load_data(t_data *data)
{
	int	i;

	i = data->length - 1;
	while (i >= 0)
	{
		push(&data->a, data->args[i]);
		if (!data->a)
			return (1);
		i--;
	}
	return (0);
}

void	sort_stack(t_data *data, int strategy)
{
	double	disorder;

	disorder = compute_disorder(data->a);
	data->disorder = disorder;
	if (strategy == 1)
		selection_sort(&data->a, &data->b, data);
	// else if (strategy == 2)
	// 	chunk_sort(&data->A, &data->B, data);
	// else if (strategy == 3)
	// 	quick_sort(&data->A, &data->B, data);
	// else
	// 	adaptive_sort(&data->A, &data->B, disorder);
}
