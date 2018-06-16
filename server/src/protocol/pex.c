/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Pex Command
*/


#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void pex_handler(player_t *player, packet_pex_t *packet)
{
	player_t *list;
	iter_t *it;

	packet->player_number = (player->client)->id;
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		send_packet(list->client, "pex", &packet);
	}
}

void pex_serialize(packet_pex_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
}