// header

void	sort_two(t_stack **a)
{
	int	one;
	int	two;

	one = (*a)->value;
	two = (*a->next)->value;
	if (one > two)
		sa(a);
}

void	sort_three(t_stack **a)
{
	int	one;
	int	two;
	int	three;

	one = (*a)-> value;
	two = (*a->next)->value;
	three = (*a->next->next)->value;
	if (one > two && one > three)
		ra(a);
	else if (two > one && two > three)
		rra(a);
	sort_two(a);
}

void	sort_five(t_stack **a)
{

}