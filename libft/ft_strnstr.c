/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:22:37 by akilk             #+#    #+#             */
/*   Updated: 2021/11/26 13:42:19 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	while (*haystack && (i + needle_len <= len))
	{
		if (!(ft_strncmp(haystack, needle, needle_len)))
			return ((char *) haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
