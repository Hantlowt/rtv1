# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hantlowt <hantlowt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/18 19:06:17 by alhote            #+#    #+#              #
#    Updated: 2016/05/04 08:28:43 by hantlowt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
OS = $(shell uname)
CC = clang
CFLAGS  = -g -Wall -Wextra -Werror -Ofast
INC_DIR = -Ilibft/includes \
			-Idraw \

SRCS = main.c world.c controller.c sphere.c vector.c maths.c draw.c camera.c\
		light.c vector_operation.c hsl.c object.c plane.c
OBJECTS = $(SRCS:.c=.o)

all: lib $(NAME)

lib:
	make -C libft/

$(NAME): $(OBJECTS)
	@echo "Compiling.."
ifeq ($(OS),Darwin)
	@$(CC) $(CFLAGS) $(OBJECTS) -Llibft/ -lft -lm -lmlx -framework OpenGL -framework AppKit -o $(NAME)
else ifeq ($(OS),Linux)
	@$(CC) $(CFLAGS) $(OBJECTS) -Llibft/ -lft -lm -lmlx -lXext -lX11 -lm -o $(NAME)
endif

%.o: %.c
	@$(CC) $(CFLAGS) $(INC_DIR) -c $<

clean:
	@make -C libft/ clean
	@rm -rf *.o
	@echo "Clean"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "Fclean"

re: fclean all
