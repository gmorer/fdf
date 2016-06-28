/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:40:19 by gmorer            #+#    #+#             */
/*   Updated: 2016/01/04 16:29:45 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*x;
	size_t	i;

	if (!(x = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	while (i < start + len)
	{
		x[i - start] = s[i];
		i++;
	}
	x[i - start] = '\0';
	return (x);
}
