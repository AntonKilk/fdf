/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:43:53 by akilk             #+#    #+#             */
/*   Updated: 2021/11/19 10:16:28 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		last;
	char	*trimmed;

	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	last = ft_strlen(s) - 1;
	while ((last >= 0)
		&& (s[last] == ' ' || s[last] == '\n' || s[last] == '\t'))
		last--;
	trimmed = (char *)malloc(sizeof(char) * (last + 2));
	if (!trimmed)
		return (NULL);
	ft_strncpy(trimmed, s, last + 1);
	trimmed[last + 1] = '\0';
	return (trimmed);
}
