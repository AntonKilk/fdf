/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:27:37 by akilk             #+#    #+#             */
/*   Updated: 2021/11/19 09:59:48 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sum = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!sum)
		return (NULL);
	i = 0;
	while (*s1)
		sum[i++] = *s1++;
	while (*s2)
		sum[i++] = *s2++;
	return (sum);
}
