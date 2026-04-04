/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:03:54 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/04 09:46:07 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr_u(int fd, unsigned int n)
{
	unsigned long	num;
	int				len;

	num = n;
	len = 0;
	if (num > 9)
		len += ft_putnbr_u(fd, num / 10);
	ft_putchar(fd, num % 10 + 48);
	len++;
	return (len);
}
