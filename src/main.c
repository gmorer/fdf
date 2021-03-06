/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:43:59 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/28 17:09:58 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_img_put(t_env *env)
{
	env->img = mlx_new_image(env->mlx, SCREEN_X, SCREEN_Y);
	ft_readprint(env);
	mlx_put_image_to_window(env->mlx, env->window, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	return (0);
}

static int	ft_key(int key, t_env *env)
{
	if (key == RIGHT || key == LEFT)
		env->xaxe += (key == RIGHT ? -0.05 : 0.05);
	if (key == DOWN || key == UP)
		env->yaxe += (key == DOWN ? -0.05 : 0.05);
	if (key == SHIFT)
		env->zoom += 0.1;
	if (key == CTR && env->zoom > 0.1)
		env->zoom -= 0.1;
	if (key == KEY_W || key == KEY_S)
		env->posy += (key == KEY_W ? -10 : 10);
	if (key == KEY_A || key == KEY_D)
		env->posx += (key == KEY_A ? -10 : 10);
	if (key == SPACE && env->side == 1)
		env->side = 0;
	else if (key == SPACE && env->side == 0)
		env->side = 1;
	if (key == ESC)
		exit(0);
	//mlx_clear_window(env->mlx, env->window);
	//ft_readprint(env);
	ft_img_put(env);
	return (1);
}

static void	freemap(t_env *env)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (env->map[y])
	{
		x = 0;
		while (env->map[y][x])
		{
			free(env->map[y][x]);
			x++;
		}
		y++;
	}
}

static int	ft_exit(t_env *env)
{
	(void)env;
	freemap(env);
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
	env->xaxe = 0;
	env->yaxe = 0;
	env->side = 1;
	env->posx = SCREEN_X / 2;
	env->posy = SCREEN_Y / 2;
	env->zoom = 4;
	if ((env->map = ft_read(argv[1])) == NULL)
		return (0);
	env->mlx = mlx_init();
	env->window = mlx_new_window(env->mlx, SCREEN_X, SCREEN_Y, "fdf");
	//mlx_key_hook(env->window, ft_key, env);
	mlx_hook(env->window,2, 3, ft_key, env);
	mlx_expose_hook(env->window, ft_img_put, env);
	mlx_hook(env->window, 17, (1L << 17), ft_exit, env);
	mlx_loop(env->mlx);
	freemap(env);
	free(env);
	return (0);
}
