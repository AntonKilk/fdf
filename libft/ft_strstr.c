/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:22:30 by akilk             #+#    #+#             */
/*   Updated: 2021/11/19 14:27:54 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*s1;
	const char	*s2;

	if (*needle == '\0')
		return ((char *) haystack);
	while (*haystack)
	{
		s1 = haystack;
		s2 = needle;
		while (*s2)
		{
			if (*s1 != *s2)
				break ;
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
