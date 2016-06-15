/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 15:47:18 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/15 13:43:10 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_line(t_line *line, t_env *env)
{
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;

	x = line->xa;
	y = line->ya;
	dx = line->xb - line->xa;
	dy = line->yb - line->ya;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(env->mlx, env->window, x, y, 0x0000FF00);
	if (dx > dy)
	{
		cumul = dx / 2;
		for (i = 1 ; i <= dx ; i++)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			mlx_pixel_put(env->mlx, env->window, x, y, 0x0000FF00);
		}
	}
	else
	{
		cumul = dy / 2;
		for (i = 1 ; i <= dy ; i++)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			mlx_pixel_put(env->mlx, env->window, x, y, 0x0000FF00);
		}
	}
}
