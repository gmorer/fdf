# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/20 11:35:32 by gmorer            #+#    #+#              #
#    Updated: 2016/06/08 16:41:06 by gmorer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = clang
CFLAGS = -L minilibx -lmlx -framework OpenGL -framework AppKit
CPATH = src/
OPATH = obj/
HPATH = inc/ libft/ minilibx_macos/
INC = $(addprefix -I , $(HPATH))
CFILES = main.c\
		 get_next_line.c\
		 libstrstr.c
OFILES = $(CFILES:.c=.o)
HFILES = inc/fdf.h libft/libft.h
OBJ = $(addprefix $(OPATH), $(OFILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft
		make -C minilibx_macos
		$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

debug: $(OBJ)
		make -C libft
		$(CC) -g  $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

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
