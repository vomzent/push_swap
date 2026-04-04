/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:03:50 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/04 09:45:45 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_puthex(int fd, uintptr_t hex_nbr, int base)
{
	char			*base_low;
	char			*base_up;
	unsigned long	num;
	int				len;

	len = 0;
	base_low = "0123456789abcdef";
	base_up = "0123456789ABCDEF";
	num = hex_nbr;
	if (num >= 16)
		len += ft_puthex(fd, num / 16, base);
	if (!base)
	{
		ft_putchar(fd, base_low[num % 16]);
		len++;
	}
	else
	{
		ft_putchar(fd, base_up[num % 16]);
		len++;
	}
	return (len);
}
