/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PFK Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void send_pfk(player_t *player)
{
	char *packet = malloc(sizeof(char) * (strlen("pfk") +
	20));
	iter_t *it;
	player_t *list;

	if (player->is_gui == 0)
		return;
	if (packet == NULL)
		exit(84);
	sprintf(packet, "pfk %d", player->client->id);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		send_unwrapped(list->client, packet);
	}
	free(packet);
}

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
		send_packet(list->client, &packet, 0);
	}
	return (true);
}

void pfk_serialize(packet_pfk_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
}