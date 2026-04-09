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
void	push(t_stack **target, int value);
int		pop(t_stack **target);
int		peek(t_stack **target);
void	free_stack(t_stack **target);
size_t	stack_size(t_stack *target);
void	print_stack(t_stack *target);

void	np_sa(t_stack **A);
void	np_sb(t_stack **B);
void	sa(t_stack **A, t_data *data);
void	sb(t_stack **B, t_data *data);
void	ss(t_stack **A, t_stack **B, t_data *data);
void	pa(t_stack **A, t_stack **B, t_data *data);
void	pb(t_stack **A, t_stack **B, t_data *data);

void	np_ra(t_stack **A);
void	np_rb(t_stack **B);
void	ra(t_stack **A, t_data *data);
void	rb(t_stack **B, t_data *data);
void	rr(t_stack **A, t_stack **B, t_data *data);

void	np_rra(t_stack **A);
void	np_rrb(t_stack **B);
void	rra(t_stack **A, t_data *data);
void	rrb(t_stack **B, t_data *data);
void	rrr(t_stack **A, t_stack **B, t_data *data);

// Algorithm operations
double	compute_disorder(t_stack *A);
int		*find_min_pos(t_stack *A);
void	selection_sort(t_stack **A, t_stack **B, t_data *data);

void	chunk_sort(t_stack **A, t_stack **B, t_data *data);
int		**create_chunk(t_stack **A, int amount);
int		*find_range(t_stack **A);
int		*scan_stack(t_stack *A, int *range);
void	retrieve_max(t_stack **A, t_stack **B);
int		retrieve_pos(t_stack *B, int found);
int		find_max(t_stack *A);
int		count_chunk(t_stack *A, int *range);
void	retrieve_chunk(t_stack **A, t_stack **B, int *range);
int		find_from_bottom(t_stack *A, int *range);
int		find_from_top(t_stack *A, int *range);
void	check_pos(t_stack **A, int *pos);

long	ft_atol(const char *string);
int		isaspace(const char p);
int		isnumber(const char p);

/// Parse input
int		check_args(char **argv, t_data *data);
int		load_data(t_data *data);
int		assign_flags(char **argv, t_data *data);
int		count_flags(char **argv);
int		convert_str(char **array, t_data *data);
int		check_duplicates(int *array, int array_len);
int		validate_strings(char **array);
int		invalid_string(char *string);
char	**parse_flags(char **argv);
int		count_args(char **argv);
int		check_strategy(char *argv);
void	sort_stack(t_data *data, int strategy);
int		array_size(char	**arg);
int		ft_strcmp(const char *s1, const char *s2);

// Benchmark
void	benchmark_mode(t_data *data);
char	*set_strategy(t_data *data);
char	*adaptive_strategy(double disorder);

// free and error
void	free_array(char **array);
void	free_data(t_data *data);
void	error(void);

// Chunk sort attempt 2
int		normalize_stack(t_stack **stack);
int		find_min(t_stack *stack);
void	print_stack_rank(t_stack *target);
void	print_stack_2(t_stack *target);


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
