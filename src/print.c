/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 11:05:40 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/17 17:53:24 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	calcxy(int x, int y, t_line *line, t_env *env)
{
	line->xb = (x - (y * env->sinxaxe)) * 5;
	line->xb = line->xb * env->zoom + env->posx;
	if (env->side == 1)
	{
		ft_putendl("lol");
		line->yb = ((y * (sin(env->yaxe / 2) * 10)) - (ft_atoi(env->map[y][x]) *
						env->sinyaxe) - ft_atoi(env->map[y][x]));
		ft_putendl("lol1");
	}
	else
	{
		line->yb = ((y * (sin(env->yaxe / 2) * 10)) + (ft_atoi(env->map[y][x]) *
						(env->sinyaxe)) + ft_atoi(env->map[y][x]));
	}
	line->yb = line->yb * 1 * env->zoom + env->posy;
	ft_mlx_line(line, env);
}

static	void	ft_getline(int x, int y, t_env *env)
{
	t_line *line;

	line = malloc(sizeof(t_line));
	line->xa = (x - (y * env->sinxaxe)) * 5;
	line->xa = line->xa * env->zoom + env->posx;
	if (env->side == 1)
		line->ya = ((y * (sin(env->yaxe / 2) * 10)) - (ft_atoi(env->map[y][x]) *
						(env->sinyaxe)) - ft_atoi(env->map[y][x]));
	else
		line->ya = ((y * (sin(env->yaxe / 2) * 10)) + (ft_atoi(env->map[y][x]) *
						(env->sinyaxe)) + ft_atoi(env->map[y][x]));
	line->ya = line->ya * 1 * env->zoom + env->posy;
	ft_putendl("start");
	if (env->map[y] && env->map[y][x + 1])
	{
		ft_putstr("x = ");
		ft_putnbr(x);
		ft_putstr("  y = ");
		ft_putnbr(y);
		ft_putendl("\nend");
		calcxy(x + 1, y, line, env);
		ft_putendl("end2");
	}
		if (env->map[y + 1] && env->map[y + 1][x])
		{
		calcxy(x, y + 1, line, env);
		}
	free(line);
}

int				ft_readprint(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	env->sinxaxe = sin(env->xaxe);
	env->sinyaxe = sin(env->yaxe);
	while (env->map[y])
	{
		x = 0;
		while (env->map[y][x])
		{
			ft_getline(x, y, env);
			x++;
		}
		y++;
	}
	return (1);
}
