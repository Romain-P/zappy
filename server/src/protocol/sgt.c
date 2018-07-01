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
	send_packet(player->client, &packet, 0);
	return (true);
}

void sgt_serialize(packet_sgt_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->time));
}

void init_bct_tile_packet(packet_bct_tile_t *packet)
{
	packet->q0 = 0;
	packet->q1 = 0;
	packet->q2 = 0;
	packet->q3 = 0;
	packet->q4 = 0;
	packet->q5 = 0;
	packet->q6 = 0;
}