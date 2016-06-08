/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:44:38 by gmorer            #+#    #+#             */
/*   Updated: 2016/06/08 15:37:16 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"

typedef struct		s_pixel
{
	int		x;
	int		y;
}					t_pixel;

typedef struct		s_env
{
	void	*mlx;
	void	*window;
	t_pixel	*pixel;
}					t_env;

int		get_next_line(int fd, char **line);
char	**ft_strstradd(char *str, char **tab);
char	**ft_strstrnew(size_t i);
size_t	ft_strstrlen(char **c);
#endif
