/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Pex Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_pex_t *pex_deserialize(char **args)
{
	return (NULL);
}

bool pex_handler(player_t *player, packet_pex_t *packet)
{
	return (false);
}

void pex_serialize(packet_pex_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
}