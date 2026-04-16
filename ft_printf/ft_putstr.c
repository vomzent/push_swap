/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/30 09:04:12 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/16 10:59:48 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putstr(int fd, char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		len += ft_putstr(fd, "(null)");
	else
	{
		while (*s)
		{
			write(fd, s++, 1);
			len++;
		}
	}
	return (len);
}
