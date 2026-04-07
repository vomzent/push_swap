/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 09:22:00 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/07 09:23:35 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnumber(const char p)
{
	return (p >= '0' && p <= '9');
}

int	isaspace(const char p)
{
	return ((p >= 9 && p <= 13) || p == ' ');
}

long	ft_atol(const char *string)
{
	int		sign;
	int		i;
	long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (isaspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
		return (ret * sign);
	while (isnumber(nptr[i]))
	{
		ret = (ret * 10) + (nptr[i] - '0');
		i++;
	}
	ret *= sign;
	return (ret);
}
