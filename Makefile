# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/20 11:35:32 by gmorer            #+#    #+#              #
#    Updated: 2016/06/15 13:29:38 by gmorer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = clang
CFLAGS = -L/usr/include -lXext -lX11 -lmlx -lm
CPATH = src/
OPATH = obj/
HPATH = inc/ libft/ minilibx/
INC = $(addprefix -I , $(HPATH))
CFILES = main.c\
		 get_next_line.c\
		 parser.c\
		 ft_mlx_lib.c\
		 print.c
OFILES = $(CFILES:.c=.o)
HFILES = inc/fdf.h libft/libft.h
OBJ = $(addprefix $(OPATH), $(OFILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft
		make -C minilibx
		$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

linux : $(OBJ)
		make -C libft
		make -C minilibx
		$(CC) $(CFLAGS) $(OBJ) libft/libft.a minilibx/libmlx.a -o $(NAME)


debug: $(OBJ)
		make -C libft
		$(CC) -g $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

$(OPATH)%.o: $(CPATH)%.c $(HFILES)
		mkdir -p $(OPATH)
		$(CC) $(CFLAGS) $(INC) $< -c -o $@


clean:
		make -C libft clean
		rm -f $(OBJ)

fclean: clean
		make -C libft fclean
		rm -f $(NAME)

re: fclean all
