/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:04:06 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/04 09:46:33 by odschreu         ###   ########.fr       */
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
