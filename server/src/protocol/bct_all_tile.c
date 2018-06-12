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
	/*
		Loop sur chaque Tile
		& Send le packet
	*/
	packet->x = 5; // Coordonnées
	packet->y = 5; // du Tile
	packet->q0 = 10;
	packet->q1 = 10;
	packet->q2 = 10;
	packet->q3 = 10;
	packet->q4 = 10;
	packet->q5 = 10;
	packet->q6 = 10;
	send_packet(player->client, "bct", &packet);
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