/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   checker.h                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: vcoevert <vcoevert@student.codam.nl>          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/15 11:34:19 by vcoevert       #+#    #+#                */
/*   Updated: 2026/04/15 15:23:37 by vcoevert     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include "push_swap.h"

char	*get_next_line(int fd);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *str, int ch);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

int		perform_operation_1(t_data *data, char *op);
int		perform_operation_2(t_data *data, char *op);
int		is_stack_sorted(t_stack *a);
void	np_pa(t_stack **a, t_stack **b);
void	np_pb(t_stack **a, t_stack **b);
#endif
