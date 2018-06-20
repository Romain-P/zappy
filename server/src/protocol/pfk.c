/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PFK Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_pfk_t *pfk_deserialize(char **args)
{
	packet_pfk_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}


bool pfk_handler(player_t *player, packet_pfk_t *packet) {
	player_t *list;
	iter_t *it;

	packet->player_number = 0;
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		send_packet(list->client, &packet);
	}
	return (true);
}

void pfk_serialize(packet_pfk_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
}