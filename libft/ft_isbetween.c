/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbetween.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:26:03 by akilk             #+#    #+#             */
/*   Updated: 2021/11/26 10:27:21 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isbetween(long long min, long long max, long long value)
{
	if (value >= min && value <= max)
	{
		return (1);
	}
	return (0);
}
