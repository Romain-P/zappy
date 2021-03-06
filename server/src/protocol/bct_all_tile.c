/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** BCT Command for all tile
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void send_bct(player_t *player)
{
	packet_bct_tile_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		exit(84);
	packet->cmd = strdup("bct");
	bct_all_handler(player, packet);
}

void send_to_all_bct(packet_bct_tile_t *packet)
{
	iter_t *it;
	player_t *list;

	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->is_gui == 1)
			send_packet(list->client, packet, 0);
	}
}

packet_bct_tile_t *bct_all_deserialize(char **args)
{
	packet_bct_tile_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool bct_all_handler(player_t *player, packet_bct_tile_t *packet)
{
	resource_t *ressource;
	iter_t *it;

	if (player->is_gui == 0)
		return (true);
	for (it = iter_begin(&(server.map).ressources); it; iter_next(it)) {
		ressource = it->data;
		init_bct_tile_packet(packet);
		get_ressource_tile(ressource->type, packet);
		packet->x = ressource->x;
		packet->y = ressource->y;
		send_packet(player->client, packet, 0);
	}
	return (true);
}

void bct_all_serialize(packet_bct_tile_t *packet, list_t *buffer)
{
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