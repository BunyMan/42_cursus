
SERVER   = server
CLIENT   = client
CC	     = cc
FLAGS    = -Wall -Werror -Wextra
RM = rm -f

HEADER = minitalk.h
# COLORS #

G			=	\033[0;32m
Y			=	\033[0;33m
R			=	\033[0;31m
O			=   \033[38;5;214m
RESET       =   \033[0m

all : $(SERVER) $(CLIENT)
		@printf "                                    \r"
		@printf "\033[2;32m               DONE!            \r"
		@sleep 0.7
		@printf "\033[1;;32m               DONE!          \n"
		@sleep 0.8

$(SERVER) : server.o utils.o utils2.o
	@$(CC) server.o utils.c utils2.c -o $(SERVER)

$(CLIENT) : client.o utils.o utils2.o
	@$(CC) client.o utils.c utils2.c -o $(CLIENT)
	@$(CC) $(FLAGS) server.o utils.c utils2.c -o $(SERVER)

$(CLIENT) : client.o utils.o utils2.o
	@$(CC) $(FLAGS) client.o utils.c utils2.c -o $(CLIENT)

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I minitalk.h

clean : 
	@rm -f *.o

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@rm -f *.o
	@printf "\033[1;91m       REMOVING ALL .o FILES\r"
		@sleep 0.2
		@printf "       REMOVING ALL .o FILES .\r"
		@sleep 0.2
		@printf "       REMOVING ALL .o FILES . . \r"
		@sleep 0.2
		@printf "       REMOVING ALL .o FILES . . . \r"
		@sleep 0.2
		@printf "                                     \r"
		@printf "\033[1;;32m               DONE!\n\r"

re: fclean all

ap: all fclean

 git:
		@printf "\n"
		@printf "					   $(RESET) @BunyMan									 \n"
		@printf "							        $(O).:::::::::::::::::::::::::::::::::::::::::::.  $(RESET)      \n"
		@printf "							       $(O)~777??77777777??77???777777777777777777??777?7\  $(RESET)    \n"
		@printf "							       $(O)~777??77777777??77???77777777777777777777777?7\  $(RESET)    \n"
		@printf "			      :~!77!~^.      .~~~             $(O).??77!77777777777777777777777777777777777777777?~   $(RESET)   \n"
		@printf "			   ^YB&@@@&@@@@P!    7@@@^  !5G.      $(O).77?~    ?7777777777777777777777!.  .7777777777?!   $(RESET)   \n"
		@printf "			  Y&@&P7^^:^!5@@@P          J@@&      $(O).77?~    ??77777777??77777777???!   .7?77777777?!   $(RESET)   \n"
		@printf "			 Y@&&!        ~7!~   ~GGG: G@&&&BB7   $(O).7??!          ^!7!   ^7777~   !!           !77?!   $(RESET)   \n"
		@printf "			:&&@P                7@&@^ ?G&&&YJ~   $(O).7??!    .::.   .!!   .7777:   !!     ...    ~77!  $(RESET)    \n"
		@printf "			^@&@5     P@&&&&&@7  7@&&^  J@&@      $(O).7??~   .7?7|!   ~7   .777?:   !7    ~777~    !7!   $(RESET)   \n"
		@printf "			 P@&&^    ^~~^7&&@7  7@&&^  J@&@.     $(O).777~   .7???:   !!   .777?:   !7    7?777.   ~?!   $(RESET)   \n"
		@printf "			 :B@@@?:     :J&&@7  7@&&^  J@&&:     $(O).777!   .??77!   !~   .7?7!.   ~7    ^777~    !7!   $(RESET)   \n"
		@printf "			  .JB&@&BGGB@@@&@P^  7@@@^  !@@@GPJ   $(O).777!   :??77!   !!.           ~!            ^7?!   $(RESET)   \n"
		@printf "			    ^7J5PGPYJ77/.     JJJ:   !YPP57   $(O).77?!...^7?77|...|7!^:....:^:::!7:..::....:^!77?!      \n"
		@printf "							      $(O).7777?7777?77??777777777777777777??77777777?77??!      \n"
		@printf "							       \\\\\\77????7??????7777777?7?????777?????77????????77      \n"

		@afplay includes/github.mp3

colors:
		./includes/teste.sh

animations: git

.PHONY: all clean fclean re



