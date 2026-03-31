/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:04:06 by odschreu          #+#    #+#             */
/*   Updated: 2026/03/30 09:04:08 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	int	len;

	len = 0;
	if (!p)
		len += ft_putstr("(nil)");
	else
	{
		len += ft_putstr("0x");
		len += ft_puthex((uintptr_t)p, 0);
	}
	return (len);
}
