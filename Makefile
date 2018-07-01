##
## EPITECH PROJECT, 2018
## nm/objdump
## File description:
## Makefile
##

server	=	zappy_server

ai =	zappy_ai

lib = libzappy_network.so

all:
	@(cd server && $(MAKE) && cp zappy_server ..)
	@(cd shared && $(MAKE) && cp $(lib) ..)
	@(cd ai && $(MAKE) && cp zappy_ai ..)

$(server):
	@(cd server && $(MAKE) && cp $(server) ..)

$(ai):
	@(cd ai && $(MAKE) && cp $(ai) ..)

$(lib):
	@(cd shared && $(MAKE) && cp $(lib) ..)

server: $(server)

ai: $(ai)

clean:
	@(cd server && ($(MAKE) clean))
	@(cd ai && ($(MAKE) clean))
	@(cd shared && ($(MAKE) clean))

fclean:
	rm -f $(server)
	rm -f $(ai)
	@(cd server && ($(MAKE) fclean))
	@(cd ai && ($(MAKE) fclean))
	@(cd shared && ($(MAKE) clean))

re: fclean all

.PHONY: clean fclean re