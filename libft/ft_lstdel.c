/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 12:34:44 by gmorer            #+#    #+#             */
/*   Updated: 2016/01/04 16:09:01 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	if (!alst)
		return ;
	while (*alst)
	{
		list = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = list;
	}
}
