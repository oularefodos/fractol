# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: foulare <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 01:21:30 by foulare           #+#    #+#              #
#    Updated: 2021/12/18 01:39:28 by foulare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fractol

NAME_B= fractol_bonus

INCLUDE= fractol.h

INCLUDE_B= fractol_bonus.h

SRCS= ft_color.c ft_error.c ft_strcmp.c julia.c  key_hook.c  mandelbrot.c fractol.c ft_calcul.c zoom.c

SRCS_B= fractol_bonus.c ft_color_bonus.c bonus.c  ft_error_bonus.c  ft_strcmp_bonus.c key_hook_bonus.c  zoom_bonus.c

CFLAGS= -Wall -Wextra -Werror libmlx.a libmlx.dylib -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDE)
	gcc $(CFLAGS) $(SRCS) -I $(INCLUDE) -o $(NAME)

bonus: $(SRCS_B) $(INCLUDE_B)
	gcc $(CFLAGS) $(SRCS_B) -I $(INCLUDE_B) -o $(NAME_B)

clean:
	rm -f $(NAME) $(NAME_B)

fclean: clean
re: fclean all bonus
