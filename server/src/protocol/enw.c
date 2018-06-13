/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** ENW Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void enw_handler(packet_enw_t *packet)
{
	player_t *player;
	iter_t *it;

	packet->player_number = 0;
	packet->egg = 0;
	packet->x = 0;
	packet->y = 0;
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		send_packet(player->client, "enw", &packet);
	}
}

void enw_serialize(packet_enw_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->egg));
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
}