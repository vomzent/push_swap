/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/16 14:11:08 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/16 10:57:37 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(long num)
{
	if (num < 10)
		return (1);
	return (1 + digits(num / 10));
}

static void	append_numbers(char *string, long num, int n, int char_amount)
{
	long	num2;
	int		i;

	i = char_amount;
	string[i--] = 0;
	while (i > 0 && n < 0)
	{
		num2 = num % 10;
		num = num / 10;
		string[i] = num2 + '0';
		i--;
	}
	while (i + 1 > 0 && n >= 0)
	{
		num2 = num % 10;
		num = num / 10;
		string[i] = num2 + '0';
		i--;
	}
}

static char	*start_string(char *string, int n, int char_amount)
{
	long	num;

	num = n;
	if (num < 0)
	{
		num *= -1;
		string[0] = '-';
	}
	append_numbers(string, num, n, char_amount);
	return (string);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		char_amount;
	long	num;

	num = n;
	if (n < 0)
		num *= -1;
	char_amount = digits(num);
	if (n < 0)
		char_amount++;
	string = (char *)malloc((char_amount + 1) * sizeof(char));
	start_string(string, n, char_amount);
	return (string);
}
