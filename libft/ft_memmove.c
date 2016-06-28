/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 09:51:43 by gmorer            #+#    #+#             */
/*   Updated: 2016/01/04 16:12:50 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmpdst;
	const unsigned char	*tmpsrc;

	tmpsrc = src;
	tmpdst = dst;
	if (len)
	{
		if (dst > src)
		{
			tmpdst += len;
			tmpsrc += len;
			while (len--)
				*--tmpdst = *--tmpsrc;
		}
		else
		{
			while (len--)
				*tmpdst++ = *tmpsrc++;
		}
	}
	return (dst);
}
