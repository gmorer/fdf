/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:44:38 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/16 17:50:13 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef __APPLE__ && __MACH__
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
#  define ESC 53
#  define SHIFT 258
#  define CTR 269
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define SPACE 49
# endif
# ifndef __LINUX__
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define ESC 65307
#  define SHIFT 65506
#  define CTR 65508
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define SPACE 32
# endif
# define SCREEN_X 1080
# define SCREEN_Y 800
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
	int		dx;
	int		dy;
	int		i;
	int		xinc;
	int		yinc;
	int		cumul;
	int		x;
	int		y;
}					t_line;

typedef struct		s_env
{
	void	*mlx;
	void	*window;
	double	xaxe;
	double	yaxe;
	double	sinxaxe;
	double	sinyaxe;
	char	***map;
	double	zoom;
	int		posx;
	int		posy;
	int		side;
}					t_env;

int					ft_readprint(t_env *env);
void				ft_mlx_line(t_line *line, t_env *env);
char				***ft_read(char *argv);
int					get_next_line(int fd, char **line);
#endif
