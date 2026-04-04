/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:03:17 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/04 09:48:12 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	convert_arg(int fd, const char *string, va_list *args)
{
	if (*(string + 1) == 'c')
		return (ft_putchar(fd, va_arg(*args, int)));
	else if (*(string + 1) == 's')
		return (ft_putstr(fd, va_arg(*args, char *)));
	else if (*(string + 1) == 'p')
		return (ft_putptr(fd, va_arg(*args, void *)));
	else if (*(string + 1) == 'd')
		return (ft_putnbr(fd, va_arg(*args, int)));
	else if (*(string + 1) == 'i')
		return (ft_putnbr(fd, va_arg(*args, int)));
	else if (*(string + 1) == 'u')
		return (ft_putnbr_u(fd, va_arg(*args, unsigned int)));
	else if (*(string + 1) == 'x')
		return (ft_puthex(fd, va_arg(*args, unsigned int), 0));
	else if (*(string + 1) == 'X')
		return (ft_puthex(fd, va_arg(*args, unsigned int), 1));
	else if (*(string + 1) == '%')
	{
		write(fd, "%", 1);
		return (1);
	}
	return (0);
}
