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

NAME = libft.a

CC = clang -g -O0

LC = ar

CFLAGS = -Wall -Wextra -Werror

LFLAGS =


HEADERS = ./include/

SRCDIR = ./src/

SRC = 	init.c \
		hooks.c \

MINILIBXDIR = ./minilibx_macos/


SRCS = $(addprefix $(SRCDIR), $(SRC))


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) -c $(SRCS) -I $(HEADERS)
	$(LC) $(LFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
	

fclean: clean
	rm -f $(NAME)

re: fclean all
