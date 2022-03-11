/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 06:32:25 by akilk             #+#    #+#             */
/*   Updated: 2022/03/10 06:33:28 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *s, char c)
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
