# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 22:36:29 by jbuny-fe          #+#    #+#              #
#    Updated: 2022/08/25 03:37:06 by jbuny-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=		so_long.c\
			get_map.c\
			check_map.c\
			extra.c\
			draw_map.c\
			map_valid.c

NAME=		so_long

OBJ=		$(SRC:.c=.o)

CC=			gcc

CFLAGS= 	-Wall -Werror -Wextra -g -fsanitize=address

LIBFT=		Libft/libft.a

LIBFT_DIR=	Libft

PRINTF=		ft_printf/libftprintf.a

PRINTF_DIR=	ft_printf

MLX=		mlx_linux/mlx_Linux.a

MLX_DIR=	mlx_linux

all: $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $(<:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O2 -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT) $(PRINTF)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(PRINTF):
	@make -s -C $(PRINTF_DIR)

debug:
	@$(CC) -g $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT) $(PRINTF)

clean:
	@rm -f $(OBJ)
	@make -s clean -C $(LIBFT_DIR)
	@make -s clean -C $(PRINTF_DIR)

fclean: clean
	@rm -f $(NAME)
	@make -s fclean -C $(LIBFT_DIR)
	@make -s fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
