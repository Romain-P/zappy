/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PFK Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool pfk_handler(packet_pfk_t *packet) {
	player_t *player;
	iter_t *it;

	packet->player_number = 0;
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		send_packet(player->client, &packet);
	}
	return true;
}

void pfk_serialize(packet_pfk_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
}