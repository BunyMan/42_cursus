# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: buny <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 19:53:54 by buny              #+#    #+#              #
#    Updated: 2023/06/08 19:58:27 by buny             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER 		= c++

COMPILERFLAGS 		= -Wall -Wextra -Werror -std=c++98

RM 			= rm -f

NAME 		= megaphone

INCLUDE 	= -I ./

SRCS 		= megaphone.cpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(COMPILER) $(COMPILERFLAGS) $(SRCS) $(INCLUDE) -c
			$(COMPILER) $(COMPILERFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

clean:
			$(RM) -r $(OBJS)

fclean : 	clean
			$(RM) $(NAME)

re:			fclean all
