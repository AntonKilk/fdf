/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:56:39 by akilk             #+#    #+#             */
/*   Updated: 2021/11/26 16:52:40 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*convert_nbr(char *str, unsigned int nbr, size_t size, int isneg)
{
	if (isneg == 0)
		str[0] = '-';
	str[size] = '\0';
	str[size - 1] = (nbr % 10) + '0';
	size--;
	nbr /= 10;
	while (nbr > 0)
	{
		str[--size] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nbr;
	size_t			size;
	int				isneg;

	size = 1;
	isneg = 0;
	if (n < 0 && size++)
		nbr = -n;
	else if (isneg == 0)
	{
		nbr = n;
		isneg += 1;
	}
	n /= 10;
	while (n)
	{
		n /= 10;
		size++;
	}
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	return (str = convert_nbr(str, nbr, size, isneg));
}
