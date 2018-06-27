/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** BCT Command for a tile
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_bct_tile_t *bct_tile_deserialize(char **args)
{
	packet_bct_tile_t *packet;

	if (str_array_length(args) != 2)
		return (NULL);
	packet = malloc(sizeof(*packet));
	if (packet == NULL)
		return (NULL);
	if (!parse_int(args[0], (int64_t *) &packet->x)
	|| !parse_int(args[1], (int64_t *) &packet->y)) {
		free(packet);
		return (NULL);
	}
	return (packet);
}

bool bct_tile_handler(player_t *player, packet_bct_tile_t *packet)
{
	resource_t *ressource;
	iter_t *it;

	init_bct_tile_packet(packet);
	for (it = iter_begin(&(server.map).ressources); it; iter_next(it)) {
		ressource = it->data;
		if (packet->x == ressource->x && packet->y == ressource->y) {
			get_ressource_tile(ressource->type, packet);
		}
	}
	send_packet(player->client, &packet);
	return (true);
}

void bct_tile_serialize(packet_bct_tile_t *packet, list_t *buffer)
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

void get_ressource_tile(size_t ressource, packet_bct_tile_t *packet)
{
	if (ressource == 0)
		packet->q0 += 1;
	if (ressource == 1)
		packet->q1 += 1;
	if (ressource == 2)
		packet->q2 += 1;
	if (ressource == 3)
		packet->q3 += 1;
	if (ressource == 4)
		packet->q4 += 1;
	if (ressource == 5)
		packet->q5 += 1;
	if (ressource == 6)
		packet->q6 += 1;
}

void init_bct_tile_packet(packet_bct_tile_t *packet)
{
	packet->q0 = 0;
	packet->q1 = 0;
	packet->q2 = 0;
	packet->q3 = 0;
	packet->q4 = 0;
	packet->q5 = 0;
	packet->q6 = 0;
}