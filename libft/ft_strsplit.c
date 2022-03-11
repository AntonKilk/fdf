/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:14:36 by akilk             #+#    #+#             */
/*   Updated: 2021/11/19 10:04:29 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int		state;
	int		count;

	count = 0;
	state = 0;
	while (*s)
	{
		if (*s != c && state == 0)
		{
			count++;
			state = 1;
		}
		else if (*s == c && state == 1)
			state = 0;
		s++;
	}
	return (count);
}

static char	**free_tab(char **tab, int x)
{
	while (x >= 0)
	{
		if (tab[x])
			free (tab[x]);
		x--;
	}
	free (tab);
	return (NULL);
}

static char	*alloc_str(char const *s, char c)
{
	int		word_len;
	char	*str;

	word_len = 0;
	while (s[word_len] != c && s[word_len])
		word_len++;
	str = ft_strnew(word_len);
	if (!str)
		return (NULL);
	str = ft_strncpy(str, s, word_len);
	return (str);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		result[i] = alloc_str(s, c);
		if (!(result[i]))
			return (free_tab (result, i));
		s += ft_strlen(result[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}
