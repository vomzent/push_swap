/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:40:06 by odschreu          #+#    #+#             */
/*   Updated: 2026/03/31 11:30:10 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct Stack{

	int				value;
	struct Stack	*next;
	struct Stack	*previous;
	// struct Stack	*previous;
	// struct Stack	*current;
} Stack;



// Stack operations
void	push(Stack **target, int value);
int		pop(Stack **target);
int		peek(Stack **target);
void	free_stack(Stack **target);

void	sa(Stack **A);
void	sb(Stack **A);
void	ss(Stack **A, Stack **B);
void	pa(Stack **A, Stack **B);
void	pb(Stack **A, Stack **B);

// Algorithm operations
double	compute_disorder(Stack *A);

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
// defining the stack structure
// reading the terminal input
// determining the state of disorder (bm always gets outputted to a txt file)
// running the algorithm that has been chosen, adaptive either chooses one algorithm based on disorder or uses internal strats
// throw an "Error\n" when there are errors
// program displays smallest list of push_swap operations possible to sort stack a, smallest num at top
// if argv2 == 0/empty, the program does not display anything and gives the prompt back
// makefile will compile all source files (it must not relink)
// push_swap 

#endif