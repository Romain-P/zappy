/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** ENW Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void send_enw(player_t *player, size_t nb)
{
	char *packet = malloc(sizeof(char) * (strlen("enw") +
	20));
	iter_t *it;
	player_t *list;

	if (packet == NULL)
		exit(84);
	sprintf(packet, "enw %zo %d %zo %zo", nb,
	player->client->id, player->x, player->y);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		send_unwrapped(list->client, packet);
	}
}

void enw_serialize(packet_enw_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->egg));
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
}