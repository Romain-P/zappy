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

	if (packet == NULL)
		exit(84);
	sprintf(packet, "ebo %zu", egg->id);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->is_gui)
			send_unwrapped(list->client, packet);
	}
	free(packet);
}

packet_ebo_t *ebo_deserialize(char **args)
{
	return (NULL);
}

bool ebo_handler(player_t *player, packet_ebo_t *packet)
{
	return (false);
}

void ebo_serialize(packet_ebo_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->egg));
}