/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:40:06 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/09 11:57:04 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*previous;
	int				rank;
	// struct t_stack	*current;
}	t_stack;


typedef struct	s_data
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				*args;
	double			disorder;
	int				strategy;
	int				total_ops;
	int				benchmark;
	int				length;
	int				ops[11];
}	t_data;

// t_stack operations
// stack_core.c
void	swap(t_stack **a);
void	push(t_stack **target, int value);
int		pop(t_stack **target);
int		peek(t_stack **target);
void	rotate(t_stack **a);

// stack_core2.c
void	reverse_rotate(t_stack **a);
void	print_stack(t_stack *target);
void	free_stack(t_stack **target);
size_t	stack_size(t_stack *target);

// stack_ops.c
void	sa(t_stack **a, t_data *data);
void	sb(t_stack **b, t_data *data);
void	ss(t_stack **a, t_stack **b, t_data *data);
void	pb(t_stack **a, t_stack **b, t_data *data);
void	pa(t_stack **a, t_stack **b, t_data *data);

// stack_ops_r.c
void	ra(t_stack **a, t_data *data);
void	rb(t_stack **b, t_data *data);
void	rr(t_stack **a, t_stack **b, t_data *data);

// stack_ops_rr.c
void	rra(t_stack **a, t_data *data);
void	rrb(t_stack **b, t_data *data);
void	rrr(t_stack **a, t_stack **b, t_data *data);

// utils.c
void	free_data(t_data *data);
void	error(void);
void	free_array(char **array);
int		array_size(char	**arg);
int		ft_strcmp(const char *s1, const char *s2);
// ft_atol.c
long	ft_atol(const char *string);

// sort_base.c
void	sort_two(t_stack **a, t_data *data);
void	sort_three(t_stack **a, t_data *data);
void	sort_four(t_stack **a, t_stack **b, t_data *data);
void	sort_five(t_stack **a, t_stack **b, t_data *data);

// parse_load.c
int		load_data(t_data *data);
void	sort_stack(t_data *data);

// parse_args.c
int		check_args(char **argv, t_data *data);
int		assign_flags(char **argv, t_data *data);
int		count_flags(char **argv);
char	**parse_flags(char **argv);
int		count_args(char **argv);

// parse_validate.c
int		check_strategy(char *argv);
int		validate_strings(char **array);
int		invalid_string(char *string);
int		convert_str(char **array, t_data *data);
int		check_duplicates(int *array, int array_len);

// benchmark.c
void	benchmark_mode(t_data *data);
char	*set_strategy(t_data *data);
char	*adaptive_strategy(double disorder);

// stack_utils.c
double	compute_disorder(t_stack *a);
void	normalize_stack(t_stack **stack);
int		find_min_rank(t_stack *stack);
int		find_min(t_stack *stack);
void	print_stack_rank(t_stack *target);

// stack_utils2.c
int		retrieve_pos(t_stack *a, int found);


// selection_sort.c
int		*find_min_pos(t_stack *A);
void	selection_sort(t_stack **A, t_stack **B, t_data *data);

// chunk_utils.c
int		**create_chunks(int stack_size);
int		chunk_size(int stack_size);
int		count_chunk(t_stack *a, int *range);
void	retrieve_chunk(t_stack **a, t_stack **b, t_data *data, int *range);
void	retrieve_max(t_stack **a, t_stack **b, t_data *data);

// chunk_utils2.c
int		find_cheapest(t_stack **a, int *range);
int		retrieve_pos_rank(t_stack *a, int rank);
int		find_max_rank(t_stack *a);

// chunk_sort.c
void	chunk_sort(t_data *data);
void	radix_sort(t_data *data);

/*


--simple
--medium
--complex
--adaptive
--bench
	// lines will be prefixed with [bench] to represent messages printed by the optional bm mode
	// displays the computed disorder, 
	// name of the straetgy used and its theoretial complexity class,
	// the total number of operations,
	// the ocunt of each operation type,
	// benchmark output must be sent to stderr and only appear when flag is present

*/
// defining the t_stack structure
// reading the terminal input
// determining the state of disorder (bm always gets outputted to a txt file)
// running the algorithm that has been chosen, adaptive either chooses one algorithm based on disorder or uses internal strats
// throw an "Error\n" when there are errors
// program displays smallest list of push_swap operations possible to sort t_stack a, smallest num at top
// if argv2 == 0/empty, the program does not display anything and gives the prompt back
// makefile will compile all source files (it must not relink)
// push_swap 

#endif
