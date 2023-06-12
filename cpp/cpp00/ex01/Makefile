COMPILER 		= c++

COMPILERFLAGS 		= -Wall -Wextra -Werror -std=c++98

RM 			= rm -f

NAME 		= phonebook

INCLUDE 	= -I ./

SRCS 		= phoneBook.cpp contact.cpp myAwesomePhonebook.cpp

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