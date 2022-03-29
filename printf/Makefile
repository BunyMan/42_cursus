# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 06:39:16 by jbuny-fe          #+#    #+#              #
#    Updated: 2022/03/22 17:17:03 by jbuny-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils1.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):
	@gcc $(FLAGS) -c -I. $(HEADER) $(SRCS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "DONE"

clean:
	@$(RM) $(OBJS)
	@$(RM) ft_printf.h.gch

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
