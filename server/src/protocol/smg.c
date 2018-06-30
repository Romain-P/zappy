/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** SMG Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_smg_t *smg_deserialize(char **args)
{
	return (NULL);
}

bool smg_handler(player_t *player, packet_smg_t *packet)
{
	return (false);
}

void smg_serialize(packet_smg_t *packet, list_t *buffer)
{
	list_add(buffer, strdup(packet->message));
}