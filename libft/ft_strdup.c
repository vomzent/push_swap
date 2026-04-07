/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 09:53:42 by odschreu          #+#    #+#             */
/*   Updated: 2026/03/19 12:58:58 by odschreu         ###   ########.fr       */
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
