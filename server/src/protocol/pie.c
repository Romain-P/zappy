/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PIE Command
*/


#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void pie_handler(packet_pie_t *packet)
{
	player_t *player;
	iter_t *it;

	packet->x = 0;
	packet->y = 0;
	packet->result = 0;
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		send_packet(player->client, "pie", &packet);
	}
}

void pie_serialize(packet_pie_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
	list_add(buffer, to_string(packet->result));
}