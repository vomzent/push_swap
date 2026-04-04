/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:33:31 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/04 09:44:03 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(int fd, const char *user_input, ...)
{
	va_list	args;
	int		len;

	va_start(args, user_input);
	len = 0;
	while (*user_input)
	{
		if (*user_input == '%' && check_percent(user_input))
		{
			len += convert_arg(fd, user_input, &args);
			user_input += 2;
		}
		if (*user_input != '%' && *user_input != 0)
		{
			ft_putchar(fd, *user_input);
			len++;
			user_input++;
		}
	}
	va_end(args);
	return (len);
}
