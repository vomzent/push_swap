#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include <stddef.h>

int	main(void)
{
	Stack	*targetA = NULL;
	Stack	*targetB = NULL;
	// Stack	*targetC = NULL;
	int		**chunks = NULL;
	int		i = 0;

	push(&targetA, 15);
	push(&targetA, -3);
	push(&targetA, 8);
	push(&targetA, -17);
	push(&targetA, 12);
	push(&targetA, -8);
	push(&targetA, 20);
	push(&targetA, -1);
	push(&targetA, 5);
	push(&targetA, -14);
	push(&targetA, 18);
	push(&targetA, -6);
	push(&targetA, 3);
	push(&targetA, -19);
	push(&targetA, 11);
	push(&targetA, -2);
	push(&targetA, 7);
	push(&targetA, -11);
	push(&targetA, 16);
	push(&targetA, -9);

	//

	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");

	int	range[2] = {-10, -5};
	int	*position = scan_stack(targetA, range);
	ft_printf("first value in range from top at pos %d\n, first value in range from bot at pos %d\n", position[0], position[1]);

	chunks = create_chunk(&targetA);

	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");
	ft_printf("Stack B:\n");
	print_stack(targetB);
	ft_printf("\n");

	while (i < 5)
	{
		ft_printf("[%d, %d], ", chunks[i][0], chunks[i][1]);
		i++;
	}
	ft_printf("\n");

	return (0);
}