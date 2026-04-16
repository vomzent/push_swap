/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoll.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/07 09:22:00 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/16 10:40:57 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	isnumber(const char p)
{
	return (p >= '0' && p <= '9');
}

static int	isaspace(const char p)
{
	return ((p >= 9 && p <= 13) || p == ' ');
}

long long	ft_atoll(const char *string)
{
	int			sign;
	int			i;
	long long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (isaspace(string[i]))
		i++;
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			sign *= -1;
		i++;
	}
	if (string[i] == '+' || string[i] == '-')
		return (ret * sign);
	while (isnumber(string[i]))
	{
		ret = (ret * 10) + (string[i] - '0');
		i++;
	}
	ret *= sign;
	return (ret);
}
