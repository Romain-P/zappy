##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Zappy
##

SRC	=	src/AIManager.cpp			\
		src/AIPlayer.cpp			\
		src/Main.cpp				\
		src/network/AIData.cpp			\
		src/network/AINetworkClient.cpp		\
		src/network/AINetworkController.cpp	\
		src/ai/AbstractAI.cpp			\
		src/ai/BasicAI.cpp

OBJ	=	$(SRC:.cpp=.o)

CFLAGS	=	-Iinclude -Wall -Werror

NAME	=	zappy_ai

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all