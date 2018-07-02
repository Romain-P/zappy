/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Command PLV
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void send_plv(player_t *player)
{
	player_t *each;
	iter_t *it;
	packet_plv_t packet = {
			.cmd = strdup("plv"),
			.level = player->level,
			.player_number = player->client->id
	};

	for (it = iter_begin(&server.players); it; iter_next(it)) {
		each = it->data;
		if (each->is_gui)
			send_packet(each->client, &packet, 0);
	}
}

static void player_get_level(int nb, packet_plv_t *packet)
{
	player_t *player;
	iter_t *it;

	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		if ((player->client)->id == nb) {
			packet->level = player->level;
			return;
		}
	}
}

packet_plv_t *plv_deserialize(char **args)
{
	packet_plv_t *packet;

	if (str_array_length(args) != 1)
		return (NULL);
	packet = malloc(sizeof(*packet));
	if (packet == NULL)
		return (NULL);
	if (args[0][0] == '#')
		args[0]++;
	if (!parse_int(args[0], (int64_t *) &packet->player_number)) {
		free(packet);
		return (NULL);
	}
	return (packet);
}

bool plv_handler(player_t *player, packet_plv_t *packet)
{
	iter_t *it;
	player_t *list;

	player_get_level(packet->player_number, packet);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->is_gui == 1)
			send_packet(list->client, packet, 0);
	}
	return (true);
}

void plv_serialize(packet_plv_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->level));
}