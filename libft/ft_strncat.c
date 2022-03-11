/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:40:09 by akilk             #+#    #+#             */
/*   Updated: 2021/11/02 14:23:54 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	count;
	char	*sum;

	sum = dest;
	count = 0;
	while (*sum != '\0')
		sum++;
	while (*src != '\0')
	{
		if (count == n)
			break ;
		*sum = *src;
		src++;
		sum++;
		count++;
	}
	*sum = '\0';
	return (dest);
}
