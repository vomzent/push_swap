/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:04:12 by odschreu          #+#    #+#             */
/*   Updated: 2026/03/30 09:08:25 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		len += ft_putstr("(null)");
	else
	{
		while (*s)
		{
			write(1, s++, 1);
			len++;
		}
	}
	return (len);
}
