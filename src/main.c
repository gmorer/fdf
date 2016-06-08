/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:43:59 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/08 15:35:06 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static int	ft_key(int key,t_env *env)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == RIGHT)
		env->pixel->x += 3;
	if (key == LEFT)
		env->pixel->x -= 3;
	if (key == DOWN)
		env->pixel->y += 3;
	if (key == UP)
		env->pixel->y -=3;
	if (key == ESC)
		exit(0);
	mlx_clear_window(env->mlx, env->window);
	ft_draw(env);
	return (1);
}

int			main(int argc, char **argv)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->pixel = (t_pixel*)malloc(sizeof(t_pixel));
	env->mlx = 0;
	env->window = 0;
	env->pixel->x = 200;
	env->pixel->y = 200;
	env->mlx = mlx_init();
	env->window = mlx_new_window(env->mlx, 400, 400, "fdf");
	ft_draw(env);
	mlx_key_hook(env->window, ft_key, env);
	mlx_loop(env->mlx);
	return (0);
}
