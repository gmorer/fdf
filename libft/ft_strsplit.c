/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:59:23 by gmorer            #+#    #+#             */
/*   Updated: 2016/01/04 16:41:36 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int		words;

	words = 0;
	while (*s)
	{
		if (c != *s && *s)
		{
			++words;
			while (c != *s && *s)
				++s;
		}
		else
			++s;
	}
	return (words);
}

static void	ft_split(char const *s, char c, char ***result)
{
	int j;
	int i;

	i = 0;
	while (*s)
	{
		while (c == *s && *s)
			++s;
		j = 0;
		while (c != *(s + j) && *(s + j))
			++j;
		if (j)
		{
			(*result)[i] = malloc(sizeof(char) * (j + 1));
			if (!(*result)[i])
				return ;
			j = 0;
			while (c != *s && *s)
				(*result)[i][j++] = *s++;
			(*result)[i++][j] = '\0';
		}
	}
	(*result)[i] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!result)
		return (NULL);
	ft_split(s, c, &result);
	return (result);
}
