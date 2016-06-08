/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:56:57 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/06 15:28:48 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	char		*buf;
	char		*t;
	static char	*save[257];
	int			r;

	if ((t = NULL) || fd < 0 || !line || BUFF_SIZE < 1 || fd > 256)
		return (-1);
	!save[fd] ? (save[fd] = ft_strnew(0)) : 0;
	if (!(buf = malloc(BUFF_SIZE + 1)) || save[fd] == NULL)
		return (-1);
	while (!(t = ft_strchr(save[fd], '\n')) &&
			((r = (int)read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[r] = '\0';
		(t = ft_strjoin(save[fd], buf)) ? free(save[fd]) : free(save[fd]);
		save[fd] = t;
	}
	free(buf);
	if (r < 0)
		return (-1);
	if (!t && save[fd][0] == '\0')
		return (0);
	*line = (t ? ft_strsub(save[fd], 0, t - save[fd]) : ft_strdup(save[fd]));
	save[fd] = (t ? ft_strcpy(save[fd], ++t) : ft_strdup("\0"));
	return (1);
}
