##
## EPITECH PROJECT, 2018
## nm/objdump
## File description:
## Makefile
##

server	=	zappy_server

ai =	zappy_ai

all:
	@(cd server && $(MAKE) && cp zappy_server ..)
	@(cd ai && $(MAKE) && cp zappy_ai ..)

$(server):
	@(cd server && $(MAKE) && cp $(server) ..)

$(ai):
	@(cd ai && $(MAKE) && cp $(ai) ..)

server: $(server)

ai: $(ai)

clean:
	@(cd server && ($(MAKE) clean))
	@(cd ai && ($(MAKE) clean))

fclean:
	rm -f $(server)
	rm -f $(ai)
	@(cd server && ($(MAKE) fclean))
	@(cd ai && ($(MAKE) fclean))

re: fclean all

.PHONY: clean fclean re
