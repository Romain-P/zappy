/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PGT Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void send_pgt(player_t *player, size_t id)
{
	char *packet = malloc(sizeof(char) * (strlen("pgt") +
	20));
	iter_t *it;
	player_t *list;

	if (player->is_gui == 0)
		return;
	if (packet == NULL)
		exit(84);
	sprintf(packet, "pgt %d %zu", player->client->id,
	id);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		send_unwrapped(list->client, packet);
	}
	free(packet);
}

packet_pgt_t *pgt_deserialize(char **args)
{
	return (NULL);
}

bool pgt_handler(player_t *player, packet_pgt_t *packet)
{
	return (false);
}

void pgt_serialize(packet_pgt_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->ressource));
}