/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** SGT Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_sgt_t *sgt_deserialize(char **args)
{
	packet_sgt_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool sgt_handler(player_t *player, packet_sgt_t *packet)
{
    packet->time = 0;
    send_packet(player->client, &packet);
    return true;
}

void sgt_serialize(packet_sgt_t *packet, list_t *buffer)
{
    list_add(buffer, to_string(packet->time));
}