/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** SEG Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_seg_t *seg_deserialize(char **args)
{
	return (NULL);
}

bool seg_handler(player_t *player, packet_seg_t *packet)
{
	return (false);
}

void seg_serialize(packet_seg_t *packet, list_t *buffer)
{
	list_add(buffer, strdup(packet->team));
}