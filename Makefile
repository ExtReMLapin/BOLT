# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 16:00:35 by pfichepo          #+#    #+#              #
#    Updated: 2016/09/19 10:26:21 by pfichepo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = clang
CFLAGS = -Wall -Werror -Wextra -O3 -msse4 -g

SRCS = init.c \
		funcs.c \
		drawline.c \
		file.c \
		funcextmain.c \
		ddraw.c \
		hook.c \
		loop.c

OBJS = $(SRCS:.c=.o)

all : libft $(NAME)

libft:
	make -C libft

mlx:
	make -C minilibx_macos

$(NAME): $(OBJS)
	make -C minilibx_macos
	$(CC) -o $(NAME) $(OBJS) -L libft/ -lft -framework OpenGL -framework AppKit -L minilibx_macos -lmlx
clean:
	make -C libft/ clean
	make -C minilibx_macos/ clean
	rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: libft mlx clean fclean all re $(NAME)
