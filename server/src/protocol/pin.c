/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PIN Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

static void set_inventory_player(packet_pin_t *packet, player_t *player)
{
	packet->x = player->x;
	packet->y = player->y;
	packet->q0 = (player->inventory).q0;
	packet->q1 = (player->inventory).q1;
	packet->q2 = (player->inventory).q2;
	packet->q3 = (player->inventory).q3;
	packet->q4 = (player->inventory).q4;
	packet->q5 = (player->inventory).q5;
	packet->q6 = (player->inventory).q6;
}

static void get_inventory_player(int nb, packet_pin_t *packet)
{
	player_t *player;
	iter_t *it;

	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		if ((player->client)->id == nb) {
			set_inventory_player(packet, player);
			return;
		}
	}
}

packet_pin_t *pin_deserialize(char **args)
{
	packet_pin_t *packet;

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

bool pin_handler(player_t *player, packet_pin_t *packet)
{
	if (player->is_gui == 0)
		return (true);
	get_inventory_player(packet->player_number, packet);
	send_packet(player->client, &packet, 0);
	return (true);
}

void pin_serialize(packet_pin_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
	list_add(buffer, to_string(packet->q0));
	list_add(buffer, to_string(packet->q1));
	list_add(buffer, to_string(packet->q2));
	list_add(buffer, to_string(packet->q3));
	list_add(buffer, to_string(packet->q4));
	list_add(buffer, to_string(packet->q5));
	list_add(buffer, to_string(packet->q6));
}