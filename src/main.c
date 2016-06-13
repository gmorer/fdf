/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:43:59 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/13 17:37:10 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static void	ft_draw(t_env *env)
{
	int i;
	int z;

	i = 0;
	while (i < 50)
	{
		z = 0;
		while (z < 50)
		{
			mlx_pixel_put(env->mlx, env->window, env->pixel->x + i, env->pixel->y + z, 0x00FF0000);
			z++;
		}
		i++;
	}
}
*/
static int	ft_key(int key,t_env *env)
{
	//ft_putnbr(key);
	//ft_putchar('\n');
	if (key == RIGHT)
		env->xaxe += 0.2;
	if (key == LEFT)
		env->xaxe -= 0.2;
	if (key == DOWN)
		env->yaxe += 0.2;
	if (key == UP)
		env->yaxe -= 0.2;
	if (key == ESC)
		exit(0);
	if (key == SHIFT)
		env->zoom += 0.1;
	if (key == CTR && env->zoom > 0.1)
		env->zoom -= 0.1;
	if (key == KEY_W)
		env->posy += 10;
	if (key == KEY_S)
		env->posy -= 10;
	if (key == KEY_A)
		env->posx += 10;
	if (key == KEY_D)
		env->posx -= 10;
	ft_putnbr(key);
	ft_putchar('\n');
	mlx_clear_window(env->mlx, env->window);
	//ft_draw(env);
	ft_readprint(env);
	return (1);
}

int			ft_exit(t_env *env)
{
	(void)env;
	exit(0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_env	*env;
	t_line	*line;

	env = (t_env*)malloc(sizeof(t_env));
	line = (t_line*)malloc(sizeof(t_line));
	env->mlx = 0;
	env->window = 0;
	env->xaxe = 5;
	env->yaxe = 0;
	env->zoom = 1;
	if((env->map = ft_read(argv[1])) == NULL)
		return (0);
	env->mlx = mlx_init();
	env->window = mlx_new_window(env->mlx, 800, 800, "fdf");
	line->xa = 10;
	line->ya = 10;
	line->xb = 170;
	line->yb = 70;
	mlx_key_hook(env->window, ft_key, env);
	mlx_hook(env->window, 17, (1L << 17), ft_exit, env);
	//ft_mlx_line(line, env);
	ft_readprint(env);
	mlx_loop(env->mlx);
	return (0);
}
