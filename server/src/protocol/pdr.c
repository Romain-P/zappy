/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PDR Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void send_pdr(player_t *player, size_t id)
{
	char *packet = malloc(sizeof(char) * (strlen("pdr") +
	20));
	iter_t *it;
	player_t *list;

	if (packet == NULL)
		exit(84);
	sprintf(packet, "pdr %d %zu", player->client->id,
	id);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->is_gui)
			send_unwrapped(list->client, packet);
	}
	free(packet);
}

packet_pdr_t *pdr_deserialize(char **args)
{
	return (NULL);
}

bool pdr_handler(player_t *player, packet_pdr_t *packet)
{
	return (false);
}

void pdr_serialize(packet_pdr_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->ressource));
}