/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** SEG Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool seg_handler(packet_seg_t *packet)
{
	player_t *player;
	iter_t *it;

	strcpy(packet->team, "LOLO");
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		send_packet(player->client, &packet);
	}
	return true;
}

void seg_serialize(packet_seg_t *packet, list_t *buffer)
{
	list_add(buffer, strdup(packet->team));
}