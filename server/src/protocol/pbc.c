/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PBC Command
*/


#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void pbc_handler(packet_pbc_t *packet)
{
	player_t *player;
	iter_t *it;

	packet->player_number = 0;
	strcpy(packet->message, "COUOU");
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		send_packet(player->client, "pbc", &packet);
	}
}

void pbc_serialize(packet_pbc_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, strdup(packet->message));
}