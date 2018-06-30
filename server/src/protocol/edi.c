/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** EDI Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_edi_t *edi_deserialize(char **args)
{
	return (NULL);
}

bool edi_handler(player_t *player, packet_edi_t *packet)
{
	return (false);
}

void edi_serialize(packet_edi_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->egg));
}