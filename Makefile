#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchaus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 19:26:29 by vchaus            #+#    #+#              #
#    Updated: 2018/02/12 14:08:08 by vchaus           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = main.c \
	errors.c \
	fract_processing.c \
	graphics_win.c \
	graphics_funcs.c \
	clear_win.c \
	clear_win_two.c \
	draw_line.c \
	fractals.c \
	fractals_funcs.c \
	fractals_calc.c \
	keyfunc_arrays.c \
	key_hook_funcs_color_flag.c \
	key_hook_funcs_fr_switch.c \
	key_hook_funcs_jul_params.c \
	key_hook_funcs_move.c \
	key_hook_funcs_zoom_num.c \
	mouse_hook_funcs.c
OBJ = $(SRC:.c=.o)
HEADER = fractol.h

LIBFT_NAME = libft.a
LIBMLX_NAME = libmlx.a
LIBFT_PATH = ./libft/
LIBFT_H_PATH = includes/
LIBMLX_PATH = ./libmlx/
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)
LIBMLX = $(LIBMLX_PATH)$(LIBMLX_NAME)

USE_LIBFT = -L $(LIBFT_PATH) -lft
LIBFT_H = -I $(LIBFT_PATH)$(LIBFT_H_PATH)
USE_LIBMLX = -L $(LIBMLX_PATH) -lmlx
LIBMLX_H = -I $(LIBMLX_PATH)
MLX_FRAMEWORKS = -framework OpenGL -framework AppKit
USE_MATH = -lm

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(USE_LIBFT) $(USE_LIBMLX) $(USE_MATH) \
	$(MLX_FRAMEWORKS) $(OBJ)

#$(NAME): $(LIBFT) $(OBJ)
#	$(CC) $(FLAGS) -o $(NAME) $(USE_LIBFT) -L /usr/local/lib/ -lmlx \
#	$(MLX_FRAMEWORKS) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(LIBMLX):
	make -C $(LIBMLX_PATH)

%.o: %.c $(HEADER)
	$(CC) -c $(FLAGS) $(LIBFT_H) $(LIBMLX_H) $<
#	$(CC) -c $(FLAGS) $(LIBFT_H) $<

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(LIBMLX_PATH) clean

re: fclean all

#===============================================================================

norm:
	norminette $(SRC) $(HEADER)
