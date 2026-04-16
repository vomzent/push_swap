/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/30 09:03:43 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/16 10:58:57 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(int fd, char c)
{
	int	len;

	len = 1;
	write(fd, &c, 1);
	return (len);
}
