/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Command PLV
*/

#include <protocol.h>
#include <util.h>
#include <zappy.h>
#include <stdlib.h>

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
	if (!parse_int(args[0], &packet->player_number)) {
		free(packet);
		return (NULL);
	}
	return (packet);
}

void plv_handler(player_t *player, packet_plv_t *packet)
{
	player_get_level(packet->player_number, packet);
	send_packet(player->client, "plv", &packet);
}

void plv_serialize(packet_plv_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->level));
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