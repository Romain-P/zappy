/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** BCT Command for all tile
*/

#include <protocol.h>
#include <util.h>
#include <zappy.h>
#include <stdlib.h>

packet_bct_tile_t *bct_all_deserialize(char **args)
{
	packet_bct_tile_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

void bct_all_handler(player_t *player, packet_bct_tile_t *packet)
{
	ressource_t *ressource;
	iter_t *it;

	for (it = iter_begin(&(server.map).ressources); it; iter_next(it)) {
		ressource = it->data;
		init_bct_tile_packet(packet);
		get_ressource_tile(ressource->ressource_number, packet);
		packet->x = ressource->x;
		packet->y = ressource->y;
		send_packet(player->client, "bct", &packet);
	}
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