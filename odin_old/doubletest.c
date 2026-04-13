#include "ft_printf/ft_printf.h"

int	main(void)
{
	double	test;

	test = 0.5566743;
	ft_printf(1, "%.%%\n", test);
	return (0);
}