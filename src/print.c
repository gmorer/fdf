/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 11:05:40 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/13 17:54:42 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int	ft_pixelcoordcal(t_env *env, int x, int y, int z)
{
	double	realx;
	double	realy;

	//if (sin(env->yaxe) < 0)
//	realy = (y * (sin(env->yaxe / 2) * 10)) + (z * (0 + (sin(env->yaxe) * 10))) + z * 10;
//	else
	realx = (x + 1) * 2 * (sin(env->xaxe) + 1);
	realy = ((y * (sin(env->yaxe / 2) * 10)) - (z * (0 + (sin(env->yaxe) * 10))) - z * 10)
		* (cos(env->xaxe) + 1);
	mlx_pixel_put(env->mlx, env->window, ((realx + 200) * env->zoom + env->posx),
			((realy + 100) * env->zoom + env->posy), 0x0000FF00);
	return (1);
}

int		ft_readprint(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (env->map[y])
	{
		x = 0;
		while (env->map[y][x])
		{
			ft_pixelcoordcal(env, x, y, ft_atoi(env->map[y][x]));
			x++;
		}
		y++;
	}
	return (1);
}
