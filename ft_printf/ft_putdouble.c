/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 11:48:16 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/04 12:36:43 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>
#include "math.h"

int	ft_putdouble(int fd, double n)
{
	int		i;
	int		len;
	char	*num;
	
	n *= 10000;
	num = ft_itoa((int)round(n));
	len = 0;
	i = 0;
	if (num[i] == '1')
	{
		len += ft_putstr(fd, "100");
		return (len);
	}
	while (i < 4)
	{
		if (i == 2)
		{
			len += ft_putchar(fd, '.');
			len += ft_putchar(fd, num[i]);
		}
		else
			len += ft_putchar(fd, num[i]);
		i++;
	}
	return (len);
}
