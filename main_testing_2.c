
int	main(void)
{
	// sa/sb checks
	sa(&targetA);
	sb(&targetB);
	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");
	ft_printf("Stack B:\n");
	print_stack(targetB);
	ft_printf("\n");
	// ss check
	ss(&targetA, &targetB);
	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");
	ft_printf("Stack B:\n");
	print_stack(targetB);
	ft_printf("\n");
	// pa/pb checks
	pa(&targetA, &targetB);
	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");
	ft_printf("Stack B:\n");
	print_stack(targetB);
	ft_printf("\n");
	pb(&targetA, &targetB);
	ft_printf("Stack A:\n");
	print_stack(targetA);
	ft_printf("\n");
	ft_printf("Stack B:\n");
	print_stack(targetB);
	ft_printf("\n");
}