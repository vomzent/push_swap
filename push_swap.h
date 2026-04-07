/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:40:06 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/07 11:57:53 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack{

	int				value;
	struct s_stack	*next;
	struct s_stack	*previous;
	// struct t_stack	*current;
} t_t_stack;

typedef struct	s_data{

	struct s_stack	*A;
	struct s_stack	*B;
	int				*args;
	double			disorder;
	int				strategy;
	int				total_ops;
	int				benchmark;
	int				ops[11];			
}	t_data;

// t_stack operations
void	push(t_stack **target, int value);
int		pop(t_stack **target);
int		peek(t_stack **target);
void	free_stack(t_stack **target);
int		stack_size(t_stack *target);
void	print_stack(t_stack *target);

void	np_sa(t_stack **A);
void	np_sb(t_stack **B);
void	sa(t_stack **A);
void	sb(t_stack **B);
void	ss(t_stack **A, t_stack **B);
void	pa(t_stack **A, t_stack **B);
void	pb(t_stack **A, t_stack **B);

void	np_ra(t_stack **A);
void	np_rb(t_stack **B);
void	ra(t_stack **A);
void	rb(t_stack **B);
void	rr(t_stack **A, t_stack **B);

void	np_rra(t_stack **A);
void	np_rrb(t_stack **B);
void	rra(t_stack **A);
void	rrb(t_stack **B);
void	rrr(t_stack **A, t_stack **B);

// Algorithm operations
double	compute_disorder(t_stack *A);
int		*find_min(t_stack *A);
void	selection_sort(t_stack **A, t_stack **B);

void	chunk_sort(t_stack **A, t_stack **B);
int		**create_chunk(t_stack **A, int amount);
int		*find_range(t_stack **A);
int		*scan_t_stack(t_stack *A, int *range);
void	retrieve_max(t_stack **A, t_stack **B);
int		retrieve_pos(t_stack *B, int	found);
int		find_max(t_stack *A);
int		count_chunk(t_stack *A, int *range);
void	retrieve_chunk(t_stack **A, t_stack **B, int *range);
int		find_from_bottom(t_stack *A, int *range);
int		find_from_top(t_stack *A, int *range);
void	check_pos(t_stack **A, int *pos);

long	ft_atol(const char *string);

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