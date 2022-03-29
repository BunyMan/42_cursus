# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbuny-fe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 19:59:53 by jbuny-fe          #+#    #+#              #
#    Updated: 2022/03/20 12:06:45 by jbuny-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
HEADER		= libft.h
INCLUDES	= -Idouble_lst -I.
FLAGS      	= -Wall -Wextra -Werror -g
RM          = rm -f

# LIBFT #
SRCS        = ft_* \
OBJS        = $(SRCS:.c=.o)

# Linked Lists #
BONUS_S		= ft_lst* \

OBJS_DLST = $(SRCS_DLST:.c=.o)

BONUS_O		= $(BONUS_S:.c=.o)

all:		$(NAME)

%.o: %.c
	@cc $(FLAGS) $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJS) $(BONUS_O) $(OBJS_DLST) $(GNL_O)
	@ar -rs $(NAME) $(OBJS) $(BONUS_O) $(OBJS_DLST) $(GNL_O)

bonus:		$(NAME) $(BONUS_O)
			@ar -rcs $(NAME) $(BONUS_O)

.c.o:
			cc $(FLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS) $(BONUS_O) $(OBJS_DLST) $(GNL_O)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

ap:			all clean

norm:
	norminette ${SRCS}

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
