/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odschreu <odschreu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:14:50 by odschreu          #+#    #+#             */
/*   Updated: 2026/04/14 12:32:33 by odschreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_token(const char *s, int c)
{
	int	j;
	int	token;

	token = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[j])
	{
		if (j == 0 && s[j] != c)
			token++;
		if (s[j] == c && s[j + 1] != 0 && s[j + 1] != c)
			token++;
		j++;
	}
	return (token);
}

static char	*copy_string(const char *token, char c)
{
	char	*dup;
	char	*start;
	int		i;
	int		j;

	i = 0;
	while (token[i] != c && token[i])
		i++;
	j = i;
	dup = malloc((i + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	start = dup;
	i = 0;
	while (i < j)
	{
		dup[i] = token[i];
		i++;
	}
	dup[i] = '\0';
	return (start);
}

static void	free_array(char **ptr_array, int pointer_count)
{
	int	i;

	i = 0;
	while (i < pointer_count)
		free(ptr_array[i++]);
}

static int	fill_array(char **ptr_array, char const *s, char c, int tokens)
{
	int	pointer_count;
	int	string_index;

	pointer_count = 0;
	string_index = 0;
	while (pointer_count < tokens && s[string_index])
	{
		while (s[string_index] == c)
			string_index++;
		if (s[string_index] != c)
		{
			ptr_array[pointer_count] = copy_string(&s[string_index], c);
			if (ptr_array[pointer_count] == NULL)
			{
				free_array(ptr_array, pointer_count);
				return (1);
			}
			pointer_count++;
		}
		while (s[string_index] != c && s[string_index])
			string_index++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_array;
	int		token_count;

	token_count = count_token(s, c);
	ptr_array = (char **)malloc((token_count + 1) * sizeof(*ptr_array));
	if (fill_array(ptr_array, s, c, token_count))
		free(ptr_array);
	else
		ptr_array[token_count] = NULL;
	return (ptr_array);
}
