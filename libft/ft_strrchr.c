/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:33:07 by akilk             #+#    #+#             */
/*   Updated: 2021/11/19 10:00:31 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen(s);
	while (n)
	{
		if (s[n] == (unsigned char)c)
			return ((char *)s + n);
		n--;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
