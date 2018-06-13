/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PNW Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void pnw_handler(packet_pnw_t *packet)
{
	player_t *player;
	iter_t *it;

	sprintf(packet->player_number, "#%d", 5); // Player Number
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		send_packet(player->client, "pnw", &packet);
	}
}

void pnw_serialize(packet_pnw_t *packet, list_t *buffer)
{
	list_add(buffer, strdup(packet->player_number));
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
	list_add(buffer, to_string(packet->orientation));
	list_add(buffer, to_string(packet->level));
	list_add(buffer, strdup(packet->name_team));
}