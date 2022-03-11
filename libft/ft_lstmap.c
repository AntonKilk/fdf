/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:16:44 by akilk             #+#    #+#             */
/*   Updated: 2021/11/25 20:18:49 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*tail;

	if (lst == NULL)
		return (NULL);
	new_lst = f(lst);
	tail = new_lst;
	lst = lst->next;
	while (lst)
	{
		tail->next = f(lst);
		tail = tail->next;
		lst = lst->next;
	}
	return (new_lst);
}
