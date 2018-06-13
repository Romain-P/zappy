/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** SMG Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void smg_handler(packet_smg_t *packet)
{
	player_t *player;
	iter_t *it;

	strcpy(packet->message, "cc c le server");
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		send_packet(player->client, "smg", &packet);
	}
}

void smg_serialize(packet_smg_t *packet, list_t *buffer)
{
	list_add(buffer, strdup(packet->message));
}