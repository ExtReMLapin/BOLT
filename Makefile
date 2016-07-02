# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 16:00:35 by pfichepo          #+#    #+#              #
#    Updated: 2015/12/01 15:29:23 by pfichepo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = clang
CFLAGS = -Wall -Werror -Wextra -Ofast -g

SRCS = 	init.c \
		funcs.c \
		funcextmain.c \
		hook.c \
		
OBJS = $(SRCS:.c=.o)

all : $(NAME)

mlx:
	make -C minilibx_macos

$(NAME): $(OBJS)
	make -C minilibx_macos
	$(CC) -o $(NAME) $(OBJS) -framework OpenGL -framework AppKit -L minilibx_macos -lmlx

clean:
	make -C minilibx_macos/ clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: mlx clean fclean all re