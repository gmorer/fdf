/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 15:31:09 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/10 18:00:20 by gmorer           ###   ########.fr       */
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

static int	testresult(char	***rslt)
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

static void	put3d(char ***rslt)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (rslt[i] != NULL)
	{
		y = 0;
		while(rslt[i][y] != NULL)
		{
			ft_putstr(rslt[i][y]);
			y++;
		}
		ft_putchar('\n');
		i++;
	}
	return;
}

static char	***getcherddd(char *argv)
{
	char ***rslt;
	int len;
	int fd;
	char *line;

	line = NULL;
	len = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		len++;
	close(fd);
	if (len == 0)
		return (NULL);
	rslt = malloc(sizeof(char**) * (len + 1));
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

	if(!(rslt = getcherddd(argv)))
	{
		ft_putendl("error");
		return (NULL);
	}
	len = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (NULL);
	}
	while (get_next_line(fd, &line) > 0)
	{
		rslt[len] = ft_strsplit(line, ' ');
		len++;
	}
	close(fd);
	put3d(rslt);
	if (testresult(rslt) == 0)
	{
		return (NULL);
	}
	ft_putendl("okay");
	return (rslt);
}
