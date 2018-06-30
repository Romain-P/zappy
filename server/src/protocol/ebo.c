/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** EBO Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void send_ebo(player_t *player, egg_t *egg)
{
	char *packet = malloc(sizeof(char) * (strlen("eht") +
	20));
	iter_t *it;
	player_t *list;

	if (player->is_gui == 0)
		return;
	if (packet == NULL)
		exit(84);
	sprintf(packet, "ebo %zu", egg->id);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		send_unwrapped(list->client, packet);
	}
	free(packet);
}

void ebo_serialize(packet_ebo_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->egg));
}