/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:44:38 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/15 16:10:39 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define SHIFT 258
# define CTR 269
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define SCREEN_X 1920
# define SCREEN_Y 1080
# define SPACE 49
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

typedef struct		s_line
{
	int		xa;
	int		ya;
	int		xb;
	int		yb;
}					t_line;

typedef struct		s_env
{
	void	*mlx;
	void	*window;
	double	xaxe;
	double	yaxe;
	char	***map;
	double	zoom;
	int		posx;
	int		posy;
	int		side;
}					t_env;

int		ft_readprint(t_env *env);
void	ft_mlx_line(t_line *line, t_env *env);
char	***ft_read(char *argv);
int		get_next_line(int fd, char **line);
#endif
