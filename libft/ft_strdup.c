/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 13:29:44 by gmorer            #+#    #+#             */
/*   Updated: 2016/01/04 16:18:46 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*s2;

	if ((s2 = malloc(sizeof(char) * ft_strlen(s1) + 1)) == NULL)
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}
