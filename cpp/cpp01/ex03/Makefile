CXX 			= c++

CXXFLAGS 		= -Wall -Wextra -Werror -std=c++98

RM 			= rm -f

NAME 		= Hi

INCLUDE 	= -I ./

SRCS 		= HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

clean:
			$(RM) -r $(OBJS)

fclean : 	clean
			$(RM) $(NAME)

re:			fclean all