/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 13:09:37 by gmorer            #+#    #+#             */
/*   Updated: 2016/01/04 16:10:03 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lsttmp;
	t_list	*new;

	if (!lst)
		return (NULL);
	lsttmp = f(lst);
	new = lsttmp;
	while ((lst = lst->next))
	{
		lsttmp->next = f(lst);
		lsttmp = lsttmp->next;
	}
	return (new);
}
