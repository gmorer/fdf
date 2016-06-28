/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:22:36 by gmorer            #+#    #+#             */
/*   Updated: 2015/12/04 12:11:10 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*x;
	char	*y;
	size_t	i;

	i = 0;
	x = malloc(size);
	y = (char*)x;
	if (size == 0)
		return (NULL);
	if (x == NULL)
		return (NULL);
	while (i < size)
	{
		y[i] = (char)0;
		i++;
	}
	return (x);
}
