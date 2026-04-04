/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:04:01 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/04 09:46:20 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr(int fd, int n)
{
	long	num;
	int		len;

	num = n;
	len = 0;
	if (num < 0)
	{
		num *= -1;
		write(fd, "-", 1);
		len++;
	}
	if (num > 9)
		len += ft_putnbr(fd, num / 10);
	ft_putchar(fd, num % 10 + 48);
	len++;
	return (len);
}
