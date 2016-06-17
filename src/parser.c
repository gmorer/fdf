/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 15:31:09 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/17 17:48:58 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int	ft_isnum(char *str)
{
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

static int	testresult(char ***rslt)
{
	int	i;
	int y;

	i = 0;
	while (rslt[i])
	{
		y = 0;
		while (rslt[i][y])
		{
			if (ft_strcmp(rslt[i][y], "") == 0 || ft_isnum(rslt[i][y]) == 0)
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

static char	***getcherddd(char *argv)
{
	char	***rslt;
	int		len;
	int		fd;
	char	*line;

	line = NULL;
	len = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		len++;
	close(fd);
	if (len == 0)
		return (NULL);
	rslt = malloc(sizeof(char**) * (len + 1));
	ft_putnbr(len);
	ft_putchar('\n');
	while (len)
	{
		rslt[len] = NULL;
		len--;
	}
	return (rslt);
}

char		***ft_read(char *argv)
{
	int		fd;
	char	***rslt;
	char	*line;
	int		len;

	if (!(rslt = getcherddd(argv)) ||
		((fd = open(argv, O_RDONLY)) == -1))
	{
		ft_putendl("usage: ./fdf [file]");
		return (NULL);
	}
	len = 0;
	while (get_next_line(fd, &line) > 0)
	{
		rslt[len] = ft_strsplit(line, ' ');
		len++;
	}
	close(fd);
	if (testresult(rslt) == 0)
	{
		ft_putendl("baf file");
		return (NULL);
	}
	return (rslt);
}
