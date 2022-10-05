# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbuny-fe <jbuny-fe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 01:36:26 by jbuny-fe          #+#    #+#              #
#    Updated: 2022/06/14 00:20:37 by jbuny-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES=	after_percent.c\
			conversion.c\
			ft_printf.c\
			ft_putchar_fd.c\
			ft_putnbrs_fd.c\
			ft_putstr_fd.c\
			ft_strcpy.c\
			ft_strlen.c

NAME=		libftprintf.a
OBJECTS=	$(SOURCES:.c=.o)
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra -g

all: $(NAME)
	
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	ranlib $(NAME)
	
clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
