/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:48:57 by gmorer            #+#    #+#             */
/*   Updated: 2016/01/04 16:22:41 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;
	int		j;

	if (!(s1 || s2))
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(x = (char*)malloc(sizeof(char) * j)))
		return (NULL);
	ft_strcpy(x, s1);
	ft_strcat(x, s2);
	return (x);
}
