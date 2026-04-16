/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/30 09:04:06 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/16 10:59:42 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(int fd, void *p)
{
	int	len;

	len = 0;
	if (!p)
		len += ft_putstr(fd, "(nil)");
	else
	{
		len += ft_putstr(fd, "0x");
		len += ft_puthex(fd, (uintptr_t)p, 0);
	}
	return (len);
}
