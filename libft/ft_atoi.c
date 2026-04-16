/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 09:25:24 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/16 10:57:09 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isnumber(const char p)
{
	return (p >= '0' && p <= '9');
}

static int	isaspace(const char p)
{
	return ((p >= 9 && p <= 13) || p == ' ');
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	ret;
	int	i;

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
	return (ret * sign);
}
