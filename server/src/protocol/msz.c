/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** MSZ Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

bool msz_handler(player_t *player, packet_msz_t *packet)
{
	if (player->is_gui == 0)
		return (true);
	packet->x = (server.map).width;
	packet->y = (server.map).height;
	send_packet(player->client, packet, 0);
	return (true);
}

packet_msz_t *msz_deserialize(char **args)
{
	packet_msz_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

void msz_serialize(packet_msz_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
}