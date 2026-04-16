/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/26 11:24:54 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/16 10:58:51 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>

int		check_percent(const char *string);
int		count_percent(const char *string);
int		ft_putchar(int fd, char c);
int		ft_putstr(int fd, char *s);
int		ft_putnbr_u(int fd, unsigned int n);
int		ft_putnbr(int fd, int n);
int		ft_puthex(int fd, uintptr_t hex_nbr, int base);
int		ft_putptr(int fd, void *p);
int		convert_arg(int fd, const char *string, va_list *args);
int		ft_putdouble(int fd, double n);
int		ft_printf(int fd, const char *user_input, ...);

#endif