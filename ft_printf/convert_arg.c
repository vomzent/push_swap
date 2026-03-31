/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:03:17 by odschreu          #+#    #+#             */
/*   Updated: 2026/03/30 09:07:19 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	convert_arg(const char *string, va_list *args)
{
	if (*(string + 1) == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (*(string + 1) == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (*(string + 1) == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (*(string + 1) == 'd')
		return (ft_putnbr(va_arg(*args, int)));
	else if (*(string + 1) == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (*(string + 1) == 'u')
		return (ft_putnbr_u(va_arg(*args, unsigned int)));
	else if (*(string + 1) == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), 0));
	else if (*(string + 1) == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 1));
	else if (*(string + 1) == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
