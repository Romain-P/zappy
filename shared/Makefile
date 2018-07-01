##
## EPITECH PROJECT, 2018
## ZAPPY
## File description:
## Makefile lib
##

SRC	=	src/client_handler.c			\
		src/packet_handler.c			\
		src/zappy_network.c			\
		src/shared/linked_list.c		\
		src/shared/network_client.c		\
		src/shared/network_connector.c		\
		src/shared/network_epoll.c		\
		src/shared/util.c			\
		src/protocol/bct.c			\
		src/protocol/broadcast.c		\
		src/protocol/connect_number.c		\
		src/protocol/ebo.c			\
		src/protocol/edi.c			\
		src/protocol/eht.c			\
		src/protocol/enw.c			\
		src/protocol/inventory.c		\
		src/protocol/look.c			\
		src/protocol/message.c			\
		src/protocol/msz.c			\
		src/protocol/pbc.c			\
		src/protocol/pdi.c			\
		src/protocol/pdr.c			\
		src/protocol/pex.c			\
		src/protocol/pfk.c			\
		src/protocol/pgt.c			\
		src/protocol/pic.c			\
		src/protocol/pie.c			\
		src/protocol/pin.c			\
		src/protocol/plv.c			\
		src/protocol/pnw.c			\
		src/protocol/ppo.c			\
		src/protocol/sbp.c			\
		src/protocol/seg.c			\
		src/protocol/sgt.c			\
		src/protocol/smg.c			\
		src/protocol/sst.c			\
		src/protocol/suc.c			\
		src/protocol/tna.c			\
		src/protocol/welcome.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude -Wall -Werror -c -fpic

LDFLAGS =	-shared -rdynamic

TARGET	=	libzappy_network.so

all: $(TARGET)

$(TARGET): $(OBJ)
	gcc ${LDFLAGS} -o $@ $^

$(SRC:.c=.d): %.d:%.c
	gcc $(CFLAGS) -MM $< >$@

clean:
	rm -f $(OBJ) $(SRC:.c=.d)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

include $(SRC:.c=.d)