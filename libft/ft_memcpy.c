/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:57:44 by gmorer            #+#    #+#             */
/*   Updated: 2015/12/09 17:14:05 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*y;
	char	*z;

	i = 0;
	y = (char*)dst;
	z = (char*)src;
	if (n == 0)
		return (y);
	while (i <= n)
	{
		y[i] = z[i];
		i++;
	}
	return (y);
}
