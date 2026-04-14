/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putdouble.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 15:49:02 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/14 16:17:07 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

static int	get_zero_count(double n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (count);
	while ((int)n == 0)
	{
		n *= 10;
		count++;
	}
	return (count);
}

int	ft_putdouble(int fd, double n)
{
	int	len;
	int	i;
	int	zero;

	i = 0;
	len = 0;
	zero = get_zero_count(n);
	if (zero > 1)
		i = 1;
	while (zero > 1)
	{
		n *= 10;
		zero--;
	}
	n *= 10;
	while (i < 4)
	{
		if (i == 2)
			len += ft_putchar(fd, '.');
		len += ft_putnbr(fd, (int)n);
		n -= (int)n;
		n *= 10;
		i++;
	}
	return (len);
}
