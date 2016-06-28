/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:22:30 by gmorer            #+#    #+#             */
/*   Updated: 2016/01/05 10:52:18 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*str;
	char	*dst;

	dst = (char*)(s1 + n);
	i = ft_strlen(s2);
	str = (char*)s1;
	if (!i)
		return ((char*)s1);
	while ((str = ft_strchr(str, *s2)) && str <= dst)
	{
		if ((str + i <= dst) && !ft_strncmp(str, s2, i))
			return (str);
		str++;
	}
	return (NULL);
}
