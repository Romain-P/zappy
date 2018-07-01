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

CXXFLAGS	=	-Iinclude -Wall -Wno-write-strings

LDFLAGS =   -L ./lib -Wl,-rpath,./lib -lzappy_network -pthread

NAME	=	zappy_ai

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(CXXFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all