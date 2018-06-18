/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** EBO Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool ebo_handler(packet_ebo_t *packet)
{
	player_t *player;
	iter_t *it;

	packet->egg = 0;
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		send_packet(player->client, &packet);
	}
	return true;
}

void ebo_serialize(packet_ebo_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->egg));
}