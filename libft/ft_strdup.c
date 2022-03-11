/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:50:45 by akilk             #+#    #+#             */
/*   Updated: 2021/11/08 19:18:42 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	str_size;

	str_size = ft_strlen(s) + 1;
	str = (char *)malloc(str_size * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, str_size);
	return (str);
}
