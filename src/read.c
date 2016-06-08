/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 15:31:09 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/08 16:41:04 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		testresult(char	**rslt)
{
	int	i;
	int y;

	i = 0;
	while (rslt[i])
	{
		y = 0;
		while (rslt[i][y])
		{
			if (rsl



}

char	***read(char *argv)
{
	int	fd;
	char	***rslt;
	char	*line;
	char	**temp;

	fd = open(argv, O_RDONLY);
	while(getnextline(fd, &line) > 0)
	{
		temp = ft_strsplit(line, ' ');
		rslt= ft_dd_add_ddd(temp, rslt);
	close(fd);
	return (rslt);
}
