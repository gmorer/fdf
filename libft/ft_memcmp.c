/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:11:38 by gmorer            #+#    #+#             */
/*   Updated: 2016/01/04 16:12:24 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	*y;

	x = (unsigned char*)s1;
	y = (unsigned char*)s2;
	i = 0;
	if (s2 == NULL && s1 == NULL)
		return (0);
	while (n--)
	{
		if (x[i] != y[i])
			return (x[i] - y[i]);
		i++;
	}
	return (0);
}
