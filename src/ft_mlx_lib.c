/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 15:47:18 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/11 17:44:59 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_line(t_line *line, t_env *env)
{
	int	e;
	int	dx;
	int	dy;
	int	y;
	int	x;

	x = line->xa;
	y = line->ya;
	dx = line->xb - line->xa;
	dy = line->yb - line->ya;
	e = dx / 2;
	while (x <= line->xb)
	{
		e += dy;
		if (e >= dx)
		{
			e -=dx;
			y += 1;
		}
		mlx_pixel_put(env->mlx, env->window, x, y, 0x0000FF00);
		x++;
	}
}
