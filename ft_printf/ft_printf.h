/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:24:54 by odschreu          #+#    #+#             */
/*   Updated: 2026/03/30 09:10:01 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>

int		check_percent(const char *string);
int		count_percent(const char *string);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbr(int n);
int		ft_puthex(uintptr_t hex_nbr, int base);
int		ft_putptr(void *p);
int		convert_arg(const char *string, va_list *args);
int		ft_printf(const char *user_input, ...);

#endif