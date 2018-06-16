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

void pnw_handler(player_t *player, packet_pnw_t *packet)
{
	player_t *list;
	iter_t *it;

	sprintf(packet->player_number, "#%d", (player->client)->id);
	packet->x = player->x;
	packet->y = player->y;
	packet->orientation = player->orientation;
	packet->level = player->level;
	strcpy(packet->name_team, (player->team).name);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		send_packet(list->client, "pnw", &packet);
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