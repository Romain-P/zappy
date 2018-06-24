##
## EPITECH PROJECT, 2018
## ZAPPY
## File description:
## Makefile
##

CXXFLAGS += -Wall -Werror -std=c++17
CXXFLAGS += -Iinclude -D linux

SRC	=	src/Main.cpp			\
		src/AIManager.cpp		\
		src/AINetworkClient.cpp		\
		src/AINetworkController.cpp	\
		src/AIPlayer.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	= 	AI

$(NAME): $(OBJ)
	g++ $(OBJ) -pthread -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
