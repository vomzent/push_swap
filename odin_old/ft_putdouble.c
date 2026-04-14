/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putdouble.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/04 11:48:16 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/14 15:49:11 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>
#include "math.h"

static char	*get_digits(double n)
{
	char	*num;
	
	if (n == 0)
		return ("0");
	n *= 10000;
	num = ft_itoa((int)round(n));
	return (num);
}

static int	check_edges(int fd, char *num)
{
	int	len;

	len = 0;
	if (num[0] == '0')
	{
		len += ft_putstr(fd, "0.00");
		return (len);
	}
	if (num[0] == '1')
	{
		len += ft_putstr(fd, "100");
		return (free(num), len);
	}
	return (0);
}

int	ft_putdouble(int fd, double n)
{
	int		i;
	int		len;
	char	*num;

	i = 0;
	if (n < 0.)
	num = get_digits(n);
	len = check_edges(fd, num);
	if (len)
		return (len);
	while (i < 4)
	{
		if (i == 2)
		{
			len += ft_putchar(fd, '.');
			len += ft_putchar(fd, num[i]);
		}
		else
			len += ft_putchar(fd, num[i]);
		i++;
	}
	return (free(num), len);
}
