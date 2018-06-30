/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PIE Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void send_pie(player_t *player)
{
	char *packet = malloc(sizeof(char) * (strlen("pie") +
	20));
	iter_t *it;
	player_t *list;

	if (player->is_gui == 0)
		return;
	if (packet == NULL)
		exit(84);
	sprintf(packet, "pie %zu %zu %zu",
	player->x, player->y, player->level);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		send_unwrapped(list->client, packet);
	}
	free(packet);
}

packet_pie_t *pie_deserialize(char **args)
{
	packet_pie_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool pie_handler(player_t *player, packet_pie_t *packet)
{
	player_t *list;
	iter_t *it;

	packet->x = 0;
	packet->y = 0;
	packet->result = 0;
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		send_packet(list->client, &packet, 0);
	}
	return (true);
}

void pie_serialize(packet_pie_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
	list_add(buffer, to_string(packet->result));
}