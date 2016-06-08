/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:58:14 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/08 16:41:08 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	ft_strstrlen(char **c)
{
	size_t i;

	i = 0;
	while (c[i] != NULL)
		i++;
	return (i);
}

char	**ft_strstrnew(size_t i)
{
	char	**rslt;
	size_t	x;

	if (!(rslt = malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	x = 0;
	while (x <= i)
		rslt[x++] = NULL;
	return (rslt);
}

char	**ft_strstrjoin(char **s1, char **s2)
{
	char	**rslt;
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	rslt = ft_strstrnew(ft_strstrlen(s1) + ft_strstrlen(s2) + 1);
	while (s1[i1] != NULL)
	{
		rslt[i1] = s1[i1];
		i1++;
	}
	while (s2[i2] != NULL)
	{
		rslt[i1 + i2] = s2[i2];
		i2++;
	}
	free(s1);
	free(s2);
	rslt[i1 + i2 + 1] = NULL;
	return (rslt);
}

char	**ft_strstradd(char *str, char **tab)
{
	char	**rslt;
	int		i;

	i = 0;
	rslt = ft_strstrnew(ft_strstrlen(tab) + 1);
	while (tab[i] != NULL)
	{
		rslt[i] = (tab[i]);
		i++;
	}
	rslt[i] = str;
	i = 0;
	free(tab);
	return (rslt);
}

char	***ft_dd_add_ddd(char **str, char ***tab)
{
	char	***rslt;
	int		i;
	int		len;

	len = 0;
	while (tab[len])
		len++;
	i = 0;
	rslt = malloc(sizeof(char**) * (len + 1));
	while (i < len)
		rslt[i] = tab[i++];
	tab[i] = str;
	tab[i + 1] = NULL;
}
