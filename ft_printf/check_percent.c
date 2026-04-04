/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 09:03:23 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/04 11:46:49 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_percent(const char *string)
{
	if (*(string + 1) == 'c'
		|| *(string + 1) == 's'
		|| *(string + 1) == 'p'
		|| *(string + 1) == 'd'
		|| *(string + 1) == 'i'
		|| *(string + 1) == 'u'
		|| *(string + 1) == 'x'
		|| *(string + 1) == 'X'
		|| *(string + 1) == '%'
		|| *(string + 1) == '.')
		return (1);
	return (0);
}
