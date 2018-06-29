##
## EPITECH PROJECT, 2018
## ZAPPY
## File description:
## Makefile
##

CFLAGS = -Iinclude -Wall -Werror -g3 -lm

SRC =	src/main.c			\
	src/mouvement.c			\
	src/player.c			\
	src/team.c			\
	src/level.c			\
	src/time_handler.c		\
	src/network/client_handler.c	\
	src/arguments/get_arguments.c	\
	src/network/packet_handler.c	\
	src/network/unwraped.c		\
	src/map/init_map.c		\
	src/map/ressource.c		\
	src/map/delete_ressource.c	\
	src/map/ressource_incantation.c \
	src/look/look.c			\
	src/look/packet.c		\
	src/look/ressource.c		\
	src/shared/linked_list.c	\
	src/shared/linked_list_utils.c	\
	src/shared/network_client.c	\
	src/shared/network_epoll.c	\
	src/shared/network_server.c	\
	src/shared/packet.c		\
	src/shared/util_1.c		\
	src/shared/util_2.c		\
	src/protocol/bct_all_tile.c	\
	src/protocol/bct_tile.c		\
	src/protocol/broadcast.c	\
	src/protocol/connect_nbr.c	\
	src/protocol/broadcast_utils.c	\
	src/protocol/ebo.c		\
	src/protocol/edi.c		\
	src/protocol/eht.c		\
	src/protocol/eject.c		\
	src/protocol/enw.c		\
	src/protocol/fork.c		\
	src/protocol/forward.c		\
	src/protocol/inventory.c	\
	src/protocol/left.c		\
	src/protocol/look.c		\
	src/protocol/incantation.c	\
	src/protocol/msz.c		\
	src/protocol/pbc.c		\
	src/protocol/pdi.c		\
	src/protocol/pdr.c		\
	src/protocol/pex.c		\
	src/protocol/pfk.c		\
	src/protocol/pgt.c		\
	src/protocol/pic.c		\
	src/protocol/pie.c		\
	src/protocol/pin.c		\
	src/protocol/plv.c		\
	src/protocol/pnw.c		\
	src/protocol/ppo.c		\
	src/protocol/right.c		\
	src/protocol/sbp.c		\
	src/protocol/seg.c		\
	src/protocol/set.c		\
	src/protocol/sgt.c		\
	src/protocol/smg.c		\
	src/protocol/sst.c		\
	src/protocol/suc.c		\
	src/protocol/take.c		\
	src/protocol/tna.c		\
	src/protocol/unwrapped.c

OBJ	=	$(SRC:.c=.o)

NAME	=	zappy_server

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
