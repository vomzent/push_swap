/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: odschreu <odschreu@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 09:53:42 by odschreu      #+#    #+#                 */
/*   Updated: 2026/04/16 10:57:53 by odschreu      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*start;
	int		i;

	i = ft_strlen(s);
	dup = malloc((i + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	start = dup;
	while (*s)
	{
		*dup++ = *s++;
	}
	*dup = '\0';
	return (start);
}
