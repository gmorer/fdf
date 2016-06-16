/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 15:47:18 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/16 17:25:44 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_line	*initline(t_line *line, t_env *env)
{
	line->x = line->xa;
	line->y = line->ya;
	line->dx = line->xb - line->xa;
	line->dy = line->yb - line->ya;
	line->xinc = (line->dx > 0) ? 1 : -1;
	line->yinc = (line->dy > 0) ? 1 : -1;
	line->dx = abs(line->dx);
	line->dy = abs(line->dy);
	line->i = 1;
	mlx_pixel_put(env->mlx, env->window, line->x, line->y, 0x0000FF00);
	return (line);
}

static t_line	*elseforline(t_line *line, t_env *env)
{
	line->cumul = line->dy / 2;
	line->i = 1;
	while (line->i <= line->dy)
	{
		line->y += line->yinc;
		line->cumul += line->dx;
		if (line->cumul >= line->dy)
		{
			line->cumul -= line->dy;
			line->x += line->xinc;
		}
		mlx_pixel_put(env->mlx, env->window, line->x, line->y, 0x0000FF00);
		line->i++;
	}
	return (line);
}

void			ft_mlx_line(t_line *line, t_env *env)
{
	line = initline(line, env);
	if (line->dx > line->dy)
	{
		line->cumul = line->dx / 2;
		while (line->i <= line->dx)
		{
			line->x += line->xinc;
			line->cumul += line->dy;
			if (line->cumul >= line->dx)
			{
				line->cumul -= line->dx;
				line->y += line->yinc;
			}
			mlx_pixel_put(env->mlx, env->window, line->x, line->y, 0x0000FF00);
			line->i++;
		}
	}
	else
		line = elseforline(line, env);
}
