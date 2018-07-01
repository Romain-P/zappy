/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PNW Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include "level.h"

void send_pnw(player_t *player)
{
	char *packet = malloc(sizeof(char) * (strlen("pnw") +
	20));
	player_t *list;
	iter_t *it;

	if (packet == NULL)
		exit(84);
	sprintf(packet, "pnw %d %zu %zu %zu %zu %s",
	(player->client)->id, player->x, player->y,
	convert_orientation(player->orientation), player->level,
	(player->team)->name);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->is_gui)
			send_unwrapped(list->client, packet);
	}
	free(packet);
}

packet_pnw_t *pnw_deserialize(char **args)
{
	return (NULL);
}

bool pnw_handler(player_t *player, packet_pnw_t *packet)
{
	return (false);
}

void pnw_serialize(packet_pnw_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
	list_add(buffer, to_string(packet->orientation));
	list_add(buffer, to_string(packet->level));
	list_add(buffer, strdup(packet->name_team));
}