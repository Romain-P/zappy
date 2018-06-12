/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** BCT Command for a tile
*/

#include <protocol.h>
#include <util.h>
#include <zappy.h>
#include <stdlib.h>

packet_bct_tile_t *bct_tile_deserialize(char **args)
{
	packet_bct_tile_t *packet;

	if (str_array_length(args) != 2)
		return (NULL);
	packet = malloc(sizeof(*packet));
	if (packet == NULL)
		return (NULL);
	if (!parse_int(args[0], &packet->x) || !parse_int(args[1], &packet->y)) {
		free(packet);
		return (NULL);
	}
	return (packet);
}

void bct_tile_handler(player_t *player, packet_bct_tile_t *packet)
{
    packet->q0 = 10;
    packet->q1 = 10;
    packet->q2 = 10;
    packet->q3 = 10;
    packet->q4 = 10;
    packet->q5 = 10;
    packet->q6 = 10;
    send_packet(player->client, "bct", &packet);
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