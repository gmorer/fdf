/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:38:24 by gmorer            #+#    #+#             */
/*   Updated: 2016/01/04 16:11:29 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*x;

	x = (unsigned char*)s;
	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			if (x[i] == (unsigned char)c)
				return ((void*)&x[i]);
			i++;
		}
	}
	return (NULL);
}
